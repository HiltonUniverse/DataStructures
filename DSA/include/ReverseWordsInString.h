#pragma once

#include <QDebug>

class ReverseWordsInString
{
    //Time complexity: O(n) for each function
    //Space complexity: O(1)
public:
    QString reverseWords(std::string & s)
    {
        std::string result;
        int r = s.length() - 1;
        int l = r;

        while(l >= 0)
        {
            while(l >= 0 && !std::isalpha(s[l]))
            {
                --l;
            }

            r = l;

            if(l < 0)
            {
                //If there were spaces after the last word and l is still >= 0, l will shift until l >=0 becomes invalid.
                //Then if we don't break here, we will have l = -1, r = -1.
                //and they will in here: result += " " + s.substr(l+1, r-l);
                //end up bing : " " + s.substr(0,0). So even though substr returns nothing, we have a " " in front of it.
                break;
            }

            while(l >= 0 && std::isalnum(s[l]))
            {
                --l;
            }

            if(result.empty())
            {
                result +=  s.substr(l+1, r-l);
            }
            else
            {
                qWarning() << l+1 <<  r-l << l << r;
                result += " " + s.substr(l+1, r-l);
            }
        }

        return QString::fromStdString(result);
    }

    //-----------------------------------
    QString betterVersion(std::string& s)
    {
        std::reverse(s.begin(), s.end());
        int l = 0, r = 0, i = 0, n = s.size();
        while (i < n)
        {
            while (i < n && s[i] != ' ')
            {
                s[r++] = s[i++];
            }

            if (l < r)
            { // if we can find a non-empty word then
                std::reverse(s.begin() + l, s.begin() + r); // reverse current word
                if (r == n) break;
                s[r++] = ' '; // set empty space
                l = r;
            }
            ++i; // now i == n or s[i] == ' ', so we skip that character!
        }
        if (r > 0 && s[r-1] == ' ')
        {
            --r; // skip last empty character if have
        }

        s.resize(r);
        return QString::fromStdString(s);
    }
};

namespace test
{
    void ReverseWordsInStringTests()
    {
        std::string test = "dlrow ";
        std::reverse(test.begin(), test.end()-1);
        qWarning() << QString::fromStdString(test);

        ReverseWordsInString reverse;
        std::string val = "the sky is blue";
//        qWarning() << reverse.reverseWords(val);

        std::string val_2 = "  hello world  ";
        qWarning() << reverse.betterVersion(val_2);
    }
}
