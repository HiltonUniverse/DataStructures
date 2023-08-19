#pragma once

#include <QDebug>
#include <iostream>
#include <regex>

class EncodeAndDecodeStrings
{
public:
    /*
     * Time complexity  : O(n)
     * Space complixity : O(1)
    */
    std::string encode(std::vector<std::string> &strs)
    {
        std::string encoded_str;

        for(const std::string& str : strs)
        {
            encoded_str += std::to_string(str.length()) + "#" + str;
        }

        return encoded_str;
    }

    /*
     * Time complexity  : O(n)
     * Space complixity : O(1)
    */
    std::vector<std::string> decode(std::string &str)
    {
        std::vector<std::string> decoded_strs;

        for(size_t i = 0; i < str.length();)
        {
            //find the first # starting from i.
            const int hash = static_cast<int>(str.find("#", i));
            //this basically does initially for 2#ca4#appl = (0,1-0), giving 2 back.
            const int length = stoi(str.substr(i, hash - i));
            //NOTE: int length = str[hash_index -1] - '0'; i have tried to use this to convert the char length
            //to int length. But this does not work if the length value is > 9. For '10' - '0', the length becomes 12544

            //then we move i to the next #, where is:
            i = hash + length + 1;
            decoded_strs.push_back(str.substr(hash + 1, length));
        }

        return decoded_strs;
    }

};

//I KNOW NOT THE BEST WAY OF TESTING BUT CAN'T AFFORD TO SPEND TIME ON WRITING UNIT TEST ATM.
namespace test
{
    //-----------------------------------
    void encodeAndDecodeStringsTest()
    {
        //FIRST INPUT
        std::vector<std::string> input{""};
        EncodeAndDecodeStrings encoder_decoder;
        std::string encoded_str = encoder_decoder.encode(input);
        //must be true
        qWarning() << (encoded_str == "0#");
        qWarning() << (encoder_decoder.decode(encoded_str) == input);

        //SECOND INPUT
        std::vector<std::string> input_second{"i", "love", "lint", "code"};
        std::string encoded_str_second = encoder_decoder.encode(input_second);
        //must be true
        qWarning() << (encoded_str_second == "1#i4#love4#lint4#code");
        qWarning() << (encoder_decoder.decode(encoded_str_second) == input_second);

    }
}
