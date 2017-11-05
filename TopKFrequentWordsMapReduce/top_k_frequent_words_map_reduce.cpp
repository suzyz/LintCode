/**
 * Definition of Input:
 * template<class T>
 * class Input {
 * public:
 *     bool done(); 
 *         // Returns true if the iteration has elements or false.
 *     void next();
 *         // Move to the next element in the iteration
 *         // Runtime error if the iteration has no more elements
 *     T value();
 *        // Get the current element, Runtime error if
 *        // the iteration has no more elements
 * }
 * Definition of Document:
 * class Document {
 * public:
 *     int id; // document id
 *     string content; // document content
 * }
 */
class TopKFrequentWordsMapper: public Mapper {
public:
    void Map(Input<Document>* input) {
        // Write your code here
        // Please directly use func 'output' to output 
        // the results into output buffer.
        // void output(string &key, int value);


        while (!input->done())
        {
            string s = input->value().content;
            int st = 0;
            for (int en = 0; en <= s.length(); ++en)
            {
                if (en == s.length() || s[en] == ' ')
                {
                    if (en > st)
                    {
                        string tmp = s.substr(st,en-st);
                        output(tmp,1); 
                    }
                    st = en+1;
                }
            }
            input->next();
        }
    }
};

class mycomparison
{
public:
    bool operator() (const pair<string,int> &a,const pair<string,int> &b)
    {
        if (a.second < b.second)
            return true;
        else
        if (a.second > b.second)
            return false;
        else
            return (a.first > b.first);
    }
};

class TopKFrequentWordsReducer: public Reducer {
public:
    int K;
    priority_queue<pair<string,int>,vector<pair<string,int>>,mycomparison> qu;

    void setUp(int k) {
        // initialize your data structure here
        K = k;
    }

    void Reduce(string &key, Input<int>* input) {
        int sum = 0;
        while (!input->done())
        {
            sum += input->value();
            input->next();
        }
        
        qu.push(make_pair(key,sum));
    }

    void cleanUp() {
        // Please directly use func 'output' to output 
        // the top k pairs <word, times> into output buffer.
        // void output(string &key, int &value);

        for (int i = 0; i < K && !qu.empty(); ++i)
        {
            pair<string,int> cur = qu.top();
            output(cur.first,cur.second);
            qu.pop();
        }
    }
};
