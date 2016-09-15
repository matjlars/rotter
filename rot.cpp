#include <string>
#include <iostream>

char rot(char c, int i)
{
	// make sure it's lowercase
	c = tolower(c);
	
	// if it's a non-word character, just return itself:
	if(c < 'a' || c > 'z') return c;
	
	c -= 26; // to ensure we don't run off the end
	c += i;
	// wrap:
	while(c < 'a'){
		c += 26;
	}
	while(c > 'z'){
		c -= 26;
	}
	return c;
}
std::string rot(std::string str, int i)
{
	int c;
	for(c = 0; c < str.size(); ++c){
		str[c] = rot(str[c], i);
	}
	return str;
}

int main()
{
	std::string input;
	
	std::cout << "input string: ";
	std::getline(std::cin, input);
	
	int i;
	for(i = 0; i < 26; ++i){
		std::cout << "rot " << i << ": " << rot(input, i) << std::endl;
	}
	
	std::cout << "HTH!" << std::endl;
	return 0;
}