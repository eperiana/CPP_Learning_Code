#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

bool                         parse_params(int argc, char** argv, string& dict_path, string& word, string& translation, vector<string>& sentence);
vector<pair<string, string>> open_dictionary(string& path);
void                         save_dictionary(string& path, vector<pair<string, string>> dict);
void                         translate(vector<string>& sentence, vector<pair<string, string>>& dict);

int main(int argc, char** argv)
{
    string dict_path, word, translation; 
    vector<string> sentence;
    string& dict_path_ref = dict_path;
    string& word_ref = word;
    string& translation_ref = translation;
    vector<string>& sentence_ref = sentence;

    if (!parse_params(argc,argv,dict_path_ref, word_ref,translation_ref, sentence_ref))
    {
        return -1;
    }

    vector<pair<string, string>> dict;
    vector<pair<string, string>>& dict_ref = dict;

    if (dict_path.length() != 0)
    {
        dict = open_dictionary(dict_path_ref);
    }
    
    if (word.length() && translation.length())
    {
        dict.emplace_back(word, translation);

        if (dict_path.length())
        {
            save_dictionary(dict_path_ref, dict_ref);
        }
    }

    if (sentence.size())
    {
        translate(sentence_ref, dict_ref);
    }

    return 0;
}

bool parse_params(int argc, char** argv, string& dict_path, string& word, string& translation, vector<string>& sentence)
{
    for (auto i = 1; i < argc; ++i)
    {
        std::string option = argv[i];

        if (option == "-d" && (i+1) < argc)
        {
            dict_path = argv[++i];
        }
        else if (option == "-a" && (i+2) < argc)
        {
            word = argv[++i];
            translation = argv[++i];
        }
        else
        {
            sentence.emplace_back(argv[i]);
        }
    }

    if (dict_path.empty())
    {
        cerr << "No dictionary path was provided." << endl;
        return false;
    }
    return true;
}

vector<pair<string, string>> open_dictionary(string& path)
{
    vector<pair<string, string>> dict;

    fstream file { path, ios_base::in };

    int i = 0;
    while (!file.eof())
    {
        string word;
        file >> word;
        
        string translation;
        file >> translation;

        if (word.compare("") != 0 && translation.compare("") != 0)
        {
            dict.emplace_back(make_pair(word, translation));
        }
    }
    
    return dict;
}

void save_dictionary(string& path, vector<pair<string, string>> dict)
{
    fstream file { path, ios_base::out };

    for (auto word_translation : dict)
    {
        file << word_translation.first << " " << word_translation.second << endl; 
    }
}

void translate(vector<string>& sentence, vector<pair<string, string>>& dict)
{
    for (auto word : sentence)
    {
        for (auto word_translation : dict)
        {
            if (word.compare(word_translation.first) == 0)
            {         
                cout << word_translation.second << " " << endl;
            }
        }
    }
}
