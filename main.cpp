#include <iostream>
std::string encrypt_caesar(std::string text, int num) {
    for (int i = 0; i < text.length(); i++) {
        if(text[i]>=97 && text[i]<=122 ){
            if(num>0)
                (text[i] + num < 122) ? text[i] = text[i] + num : text[i] = 97 + ((text[i] + num) - 123);
            else
                (text[i] + num >= 97) ? text[i] = text[i] + num : text[i] = 123 + ((text[i] + num) - 97);
        }
        if(text[i]>=65 && text[i]<=90){
            if(num>0)
                (text[i] + num < 90) ? text[i] = text[i] + num:text[i] = 65 + ((text[i] + num) - 91);
            else
                (text[i] + num >= 65) ? text[i] = text[i] + num : text[i] = 91 + ((text[i] + num) - 65);
        }
    }
    return text;
}
std::string decrypt_caesar(std::string text, int num){

    return encrypt_caesar(text,-num);
}


int main() {
    std::cout << "Encrypt_caesar\n";
    std::string text;
    std::string question;
    int num = 0;
    std::cout << "Input text :";
    std::getline(std::cin, text);
    std::cout << "Enter by what number you need to shift :" << std::endl;
    std::cin >> num;
    (num>0)? num=num%26 : num=num%-26;
    bool ques=true;
    do {
        std::cout << "Need to encrypt or decrypt ?";
        std::cin >> question;
        if(question=="encrypt" ||question=="decrypt")
            ques = false;
    }
    while(ques);

    (question=="encrypt")? std::cout << encrypt_caesar(text, num) << std::endl :
    std::cout <<decrypt_caesar(text,num)<<std::endl;
}
