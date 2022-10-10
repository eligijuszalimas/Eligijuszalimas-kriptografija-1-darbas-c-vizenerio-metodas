#include<iostream>

using namespace std;

string ILGIS(string tekstas, string key)
{
    int x = tekstas.size();

    for (int i = 0; ; i++)
    {
        if (x == i)
            i = 0;
        if (key.size() == tekstas.size())
            break;
        key.push_back(key[i]);
    }
    return key;
}

string cipherText(string tekstas, string key)
{
    string cipher_text;

    for (int i = 0; i < tekstas.size(); i++)
    {   
        // converting in range 0-25
        char x = (tekstas[i] + key[i]) % 127;
        
        // convert into alphabets(ASCII)
     

        cipher_text.push_back(x);
    }
    return cipher_text;
}



string originalText(string cipher_text, string key)
{
    string orig_text;

    for (int i = 0; i < cipher_text.size(); i++)
    {
        char x;
       
         x = (cipher_text[i] - key[i] + 127) % 127;

  
        orig_text.push_back(x);
    }
    return orig_text;
}

int main()
{
    string tekstas;
    string keyword;

    cout << "iveskite norima teksta sifravimui  :" << endl;
    cin >> tekstas;

    cout << "iveskite norima teksta sifravimui  :" << endl;
    cin >> keyword;


    string key = ILGIS(tekstas, keyword);
    string cipher_text = cipherText(tekstas, key);

    cout << "Pasleptas : " <<endl<<cipher_text << endl;
    cout << "Orginalus tekstas : " << endl << originalText(cipher_text, key) << endl;











    return 0;
}