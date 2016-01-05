//
// Frank Derry Wanye
//

#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <regex>
#include <iomanip>

using namespace std;

#ifndef ONLINE_JUDGE
const string test_data = "This is a simple file of test data, which should "
        "not cause your program any trouble. Do note that it contains several"
        " punctuation characters. Of course,this is not really a problem, "
        "because such characters are treated in the same way as spaces.\n"
        "#\n"
        "I I'i'ke to play cricket\n"
        "#\n"
        "The nightmare at a Colorado Springs Planned Parenthood clinic is "
        "over. Now comes the time to sort through the sad, sordid, alarming "
        "aftermath.\n"
        "#\n"
        "Three people were shot dead Friday, including university police "
        "Officer Garrett Swasey, whose body was escorted out early Saturday "
        "morning by his fellow officers. Five officers and four civilians are "
        "hospitalized in good condition, according to city police Lt. Catherine "
        "Buckley, after the assault.\n"
        "#\n"
        "And then there's the challenge of making sense of all this "
        "bloodshed: Why, on the day after Thanksgiving, would a man walk up to "
        "a clinic with his guns out and then hold out for hours before finally "
        "surrendering?\n"
        "#\n"
        "Planned Parenthood, which delivers reproductive health care and sex "
        "education to women and men across the United States, has come under "
        "attack before. But the group has said that it didn't know anything "
        "about this facility being targeted deliberately.\n"
        "#\n"
        "Our hearts break together, Planned Parenthood of the Rocky Mountains "
        "President Vicki Cowart told those gathered Saturday at a service in a "
        "Colorado Springs church.\n"
        "#\n"
        "We have so many questions. We don't know yet why this happened.\n"
        "#\n"
        "And authorities have not outlined a motive in Friday's incident that"
        " had those in the clinic huddling in horror and others hunkering down "
        "in fear in nearby stores and offices.\n"
        "#\n"
        "They have, however, identified the man they say is responsible: "
        "57-year-old Robert Lewis Dear.\n"
        "#\n"
        ""
        "#";
#endif

class Paragraph {
private:

public:
    string word;
    unordered_map<string,int> words;
    pair<string,int> max_word;

    string lowercaseof(const string& word) const {
        string out = word;
        for (int k = 0; k < word.length(); k++)
        {
            out[k] = tolower(word[k]);
        }
        return out;
    }

    void readData(istream& input) {
        max_word = make_pair("",-1);
        while (word != "#") {
            //Makes sure word contains only letters
            regex reg1("[A-Za-z]+");
            //Used to replace non-letter parts of word with spaces
            regex reg2("[^A-Za-z\\s]");
            //If word contains only letters, add to map
            if (regex_match(word, reg1)) {
                increment(word);
            }
            else {
                //Else replace all non-letters with spaces
                word = regex_replace(word, reg2, " ");
                auto it = word.find(" ");
                vector<int> v;
                for(int i = 0; i < word.size(); ++i)
                    if(word[i]==' ')
                        v.push_back(i);
                int begin = 0;
                int last = -1;
                if(!v.empty()) {
                    for (int j = 0; j < v.size(); ++j) {
                        string t1 = word.substr(last+1, v[j]-(last+1));
                        if (regex_match(t1, reg1))
                            increment(t1);
                        last = v[j];
                    }
                    string t1 = word.substr(last+1);
                    if (regex_match(t1,reg1))
                        increment(t1);
                }
            }
            input >> word;
        }
    }

    /*
     * Prints out maximum word
     */
    void solveIt() {
        cout << setw(4) << max_word.second << " " << max_word.first << "\n";
        words.clear();
    }

    void increment(string& word) {
        if(word == "")
            return;
        word = lowercaseof(word);
        words[word]++;
        if(words[word]>max_word.second)
            max_word = make_pair(word,words[word]);
    }
};

int main() {
    Paragraph para;

#ifndef ONLINE_JUDGE
    istringstream data (test_data);
#else
    istream& data = cin;
#endif
    while(data >> para.word) {
        para.readData(data);
        if(!para.words.empty())
            para.solveIt();
        else
            return 0;
    }

    return 0;
}
