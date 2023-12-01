#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>

using namespace std;

const int ENGLISH = 1;
const int GERMAN = 2;

struct TVocab
{
    char english[54 + 1];
    char german[54 + 1];
};

size_t count(char *arr, char c)
{
    size_t count = 0;
    for (auto i = 0; i < strlen(arr); ++i)
        if (arr[i] == c) ++count;
    return count;
}

void shuffle(TVocab **arr, size_t len)
{
    srand(time(NULL));
    for (auto i = 0; i < len; ++i)
    {
        auto to = (rand() + rand() * RAND_MAX) % len;
        if (i != to) swap(arr[i], arr[to]);
    }
}

void removeCharsFromCharArray(char *arr, const char *charsToRemove, const char flag, bool alsoRemoveFlags = false)
{
    bool isFlag = false;
    size_t j=0;
    for (size_t i = 0; arr[i]; i++)
    {
        if (arr[i] == flag)
        {
            isFlag = !isFlag;
            if (alsoRemoveFlags) continue;
        }
        if (!isFlag && strchr(charsToRemove, arr[i])) continue;
        arr[j++] = arr[i];
    }
    arr[j] = 0;
}

void vocabToJson(TVocab *vocab, char *json, size_t vocabCount)
{
    if (vocabCount == 0)
    {
        json = (char *)"{\n}";
        return;
    }
    auto ret = stringstream();
    ret << "{\n";
    for (auto i = 0; i < vocabCount - 1; ++i)
        ret << "\t\"" << vocab[i].english << "\" : " << "\"" << vocab[i].german << "\",\n";
    ret << "\t\"" << vocab[vocabCount - 1].english << "\" : " << "\"" << vocab[vocabCount - 1].german << "\"\n}";
    auto jsonString = ret.str();
    for (auto i = 0; i < jsonString.size(); ++i) json[i] = jsonString[i];
    json[jsonString.size()] = 0;
}

void jsonToVocab(char *json, TVocab *vocab, size_t vocabCount)
{
    removeCharsFromCharArray(json, "{}\n\t ", '\"', true);
    auto jsonIterator = 0;
    auto jsonLength = strlen(json);
    for (auto i = 0; i < vocabCount; ++i)
    {
        vocab[i] = TVocab();
        for (auto j = 0; json[jsonIterator] != ':' && jsonIterator < jsonLength; ++jsonIterator, ++j)
            vocab[i].english[j] = json[jsonIterator];
        ++jsonIterator;
        for (auto j = 0; json[jsonIterator] != ',' && jsonIterator < jsonLength; ++jsonIterator, ++j)
            vocab[i].german[j] = json[jsonIterator];
        ++jsonIterator;
    }
}

void writeToFile(const char *filename, const char *content)
{
    ofstream writer;
    writer.open(filename, ios::out);
    if (!writer) return;
    writer << content;
    writer.close();
}

char *readFromFile(const char *filename)
{
    ifstream reader;
    reader.open(filename, ios::in);
    if (!reader) return nullptr;
    reader.seekg(0, ios::end);
    auto len = (int)reader.tellg();
    reader.seekg(0, ios::beg);
    auto loadedFile = new char[len+1];
    reader.read(loadedFile, len);
    loadedFile[len-count(loadedFile, '\n')] = 0;
    reader.close();
    return loadedFile;
}

void testVocab(TVocab *vocab, size_t vocabCount)
{
    cout << "Select a language:" << endl
        << "1: english" << endl
        << "2: german" << endl;
    auto language = 0;
    cin >> language;
    if (language < ENGLISH || language > GERMAN)
    {
        cout << "Are you stupid? That wasn't an option!" << endl << endl;
        return;
    }
    TVocab **vocabPtrs = new TVocab*[vocabCount];
    for (auto i = 0; i < vocabCount; ++i) vocabPtrs[i] = &vocab[i];
    shuffle(vocabPtrs, vocabCount);
    auto rightAnswers = 0;
    auto wrongAnswers = 0;
    for (auto i = 0; i < vocabCount; ++i)
    {
        cout << (language == ENGLISH ? vocabPtrs[i]->english : vocabPtrs[i]->german) << ": ";
        char input[54 + 1];
        cin >> input;
        if (strcmp(input, language == ENGLISH ? vocabPtrs[i]->german : vocabPtrs[i]->english))
        {
            cout << "wrong you loser!" << endl << endl;
            ++wrongAnswers;
        }
        else
        {
            cout << "you're not as stupid as I thought" << endl << endl;
            ++rightAnswers;
        }
    }

    if (rightAnswers == 0)
        cout << "You were not able to translate anything correctly. You were to stupid all " << wrongAnswers << " vocabs." << endl << endl;
    else if (wrongAnswers == 0)
        cout << "You were able to translate all " << rightAnswers << " vocabs correctly. Congratulations!" << endl << endl;
    else 
        cout << "You translated " << rightAnswers << " words correctly, but you were to stupid for the remaining " << wrongAnswers << "." << endl << endl;

    delete[] vocabPtrs;
}

void printVocab(TVocab *vocab, size_t vocabCount)
{
    cout << endl << "Saved vocab:" << endl;
    if (vocabCount == 0)
    {
        cout << "-- none --" << endl;
        return;
    }
    cout << setw(15) << right << "english" << " | " << setw(15) << left << "german" << endl
        << "----------------|----------------" << endl;
    for (auto i = 0; i < vocabCount; i++)
        cout << setw(15) << right << vocab[i].english << " | " << setw(15) << left << vocab[i].german << endl;
    cout << endl;
}

void getNewVocab(TVocab *&vocab, size_t &vocabCount)
{
    int newVocabCount = 0;
    cout << "How many vocabs do you want to add? ";
    cin >> newVocabCount;
    TVocab *newVocab = new TVocab[vocabCount + newVocabCount];
    for (auto i = 0; i < vocabCount; ++i) newVocab[i] = vocab[i];
    delete[] vocab;
    vocab = newVocab;
    auto i = vocabCount;
    vocabCount += newVocabCount;
    for (; i < vocabCount; ++i)
    {
        vocab[i] = TVocab();
        cout << "Insert new vocab:" << endl
            << "English: ";
        cin >> vocab[i].english;
        cout << "German: ";
        cin >> vocab[i].german;
        cout << endl;
    }
    cout << endl;
}

int main()
{
    auto filename = "C:/Users/Tobias.Schaelte/Desktop/Vokabeln.txt";
    auto vocabAsJson = readFromFile(filename);
    auto vocabCount = count(vocabAsJson, ':');
    auto vocab = new TVocab[vocabCount];
    jsonToVocab(vocabAsJson, vocab, vocabCount);
    delete[] vocabAsJson;

    while (true)
    {
        auto userInput = 0;
        cout << "What do you want to do?" << endl
            << "0: exit" << endl
            << "1: learn vocabs" << endl
            << "2: view vocabs in dictionary" << endl
            << "3: add vocabs to dictionary" << endl;
        cin >> userInput;
        if (userInput == 0) break;
        switch (userInput)
        {
        case 0:
        case 1:
            testVocab(vocab, vocabCount);
            break;
        case 2:
            printVocab(vocab, vocabCount);
            break;
        case 3:
            getNewVocab(vocab, vocabCount);
            char *json = new char[5000];
            vocabToJson(vocab, json, vocabCount);
            writeToFile(filename, json);
            delete[] json;
            break;
        }
    }
    delete[] vocab;
}