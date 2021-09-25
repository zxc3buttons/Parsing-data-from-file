#include <iostream>
#include <string>
#include <fstream>
#include <bitset>
using namespace std;

//ex 1, part 1
void read(string address)
{
    ifstream in(address);

    string text;
    if (in.is_open())
    {
        while (getline(in, text))
        {
            cout << text << endl;
        }
    }
    else
    {
        cout << "File not found";
    }

    in.close();
}


//ex 1, part 2
void read_only_even_numbers(string address, string new_address)
{
    ifstream in(address);
    string text;

    if (in.is_open())
    {
        getline(in, text);

    }
    else
    {
        cout << "File not found";
    }

    in.close();

    ofstream out(new_address);

    if (out.is_open())
    {
        for (size_t i = 0; i < text.length(); i++)
        {
            if (text[i] % 2 == 0)
            {
                out << text[i];
            }

        }
    }

    out.close();

}
int size_of(string address) {

    ifstream in(address);
    string str = "";
    int n = 0;

    if (in.is_open()) {
        while (getline(in, str)) {
            n++;
        }
    }

    return n;
}
//ex 2 p5
string* keys(string address) {

    ifstream in(address);
    string str = "";
    int n = size_of(address);

    string* keys = new string[n];
    str = "";
    int index = 0;

    if (in.is_open()) {

        while (getline(in, str)) {

            string key = "";
            for (size_t i = 0; i < str.length(); i++) {

                if (str[i] == '-') {
                    break;
                }

                key += str[i];
            }

            keys[index] = key;
            index++;
        }
    }
    in.close();
    return keys;
}

//ex 2 part 1
void format(string address, string new_address)
{
    ifstream in(address);

    int n = size_of(address);//размер массива строк
    string str;
    string* old_strings = NULL;
    string* new_strings = NULL;

    old_strings = new string[n];//массив данных в ASCII представлении
    new_strings = new string[n];//массив данных в бинарном представлении
    str = "";


    if (in.is_open()) {
        int i = 0;
        while (getline(in, str)) {

            int default_index_of_data = 0;
            for (size_t i = 0; i < str.length(); i++) {

                if (str[i] == '-') {
                    default_index_of_data++;
                    break;
                }

                default_index_of_data++;
            }

            for (int j = default_index_of_data; j < str.length(); j++) {
                old_strings[i] += str[j];
            }

            i++;
        }
    }

    in.close();

    for (int i = 0; i < n; i++) {

        new_strings[i] += keys(address)[i] + "-";

        for (size_t j = 0; j < old_strings[i].length(); j++) {
            new_strings[i] += bitset<8>(old_strings[i][j]).to_string();
        }
    }

    ofstream out(new_address);

    if (out.is_open()) {
        for (int i = 0; i < n; i++) {
            out << new_strings[i] << endl;
        }
    }

    out.close();
    delete[] new_strings;
}
//ex 2 part 2
void output(string address) {

    ifstream in(address);

    if (in.is_open()) {

        string str = "";
        while (getline(in, str)) {
            cout << str << endl;
        }
    }

    in.close();
}
//ex 2 part 3 - searching numero of certain note
int search(string address, string key) {

    ifstream in(address);
    string str = "";
    int numero = 0;

    if (in.is_open()) {
        while (getline(in, str)) {
            for (size_t i = 0; i < key.length(); i++) {
                if (str[i] != key[i]) {
                    numero++;
                    break;
                }
                in.close();
                return numero;
            }
        }
    }
    else {
        return -2;
    }

    in.close();
    return -1;
}
//ex 2 part 4
string search_by_index(string address, int index) {

    ifstream in(address);
    string str = "";
    int current_index = 0;

    if (in.is_open()) {
        while (getline(in, str)) {

            int default_index_of_data = 2;
            for (size_t i = 2; i < str.length(); i++) {

                if (str[i] == '-') {
                    default_index_of_data++;
                    break;
                }

                default_index_of_data++;
            }

            if (current_index == index) {

                string required_str = "";
                for (size_t i = default_index_of_data; i < str.length(); i++) {
                    required_str += str[i];
                }

                in.close();
                return required_str;
            }

            current_index++;
        }

        return "not found by this index";
    }

    return "file is not found";
}


//ex2 p6
string search_by_key(string address, string key) {

    ifstream in(address);
    string str = "";

    for (int i = 0; i < size_of(address); i++) {
        if (key == keys(address)[i]) {
            return search_by_index(address, i);
        }
    }

    return "not found";

}
//ex 3 - sort function
void sort(string address) {

    fstream file(address);
    string str = "";

    if (file.is_open()) {
        getline(file, str);
    }

    int sorted_array[10] = { 0 };

    for (size_t i = 0; i < str.length(); i++) {

        sorted_array[str[i] - 48] = 1;

    }
    file.close();

    ofstream outfile("C:/Users/Олег/Desktop/all needed/с++/sorted.txt");

    for (size_t i = 0; i < str.length(); i++) {
        if (sorted_array[i] == 1) outfile << i;
    }

    outfile.close();
}

int main()
{
    string address = "C:/Users/Олег/Desktop/all needed/с++/input.txt";
    string new_address = "C:/Users/Олег/Desktop/all needed/с++/output.txt";

    format(address, new_address);
    
}



