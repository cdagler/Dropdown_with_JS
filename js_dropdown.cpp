// File Name: js_dropdown.cpp
//
// This takes a tabbed list of items and turns them into a set of bootstrap
// dropdown menus.
//
// Here is an example on how to do this:
//		g++ js_dropdown.cpp -o js_dropdown.o
//		./js_dropdown.o < contents.txt > contents.js
//		Then add "<script src="contents.js"></script>" to your HTML page.
//
// Author: Clay Dagler (cdagler@egusd.net)

#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
using namespace std;
const int MAX_NUM_LINES = 10000;

class JS_Dropdown
{
public:
	JS_Dropdown();
	void readInLines(void);
	void outputToJS(void);

private:
	void printWithTabs(int n, const string& s);
	string itos(int i);
	static const bool debug = false;
	int numOfTabs[MAX_NUM_LINES];
	string content[MAX_NUM_LINES];
	string title;
	int numOfLines;
};

JS_Dropdown::JS_Dropdown()
{
	if(debug)
		cout << "Let's get it started." << endl << endl;

	title = "";
	numOfLines = 0;
}

void JS_Dropdown::readInLines(void)
{
	if(debug)
		cout << "Reading in the lines from cin." << endl << endl;

	string currentLine;
	int i=0;

	getline(cin, title);
	title=title.substr(0,title.size()-(i+1));

	while(getline(cin, currentLine))
	{
		i=0;
		while(currentLine[i]==',' || currentLine[i]=='\t')
			i++;
		numOfTabs[numOfLines]=i;
		content[numOfLines]=currentLine.substr(i,currentLine.size()-(i+1));
		numOfLines++;
		if(numOfLines >=MAX_NUM_LINES)
		{
			cout << "\aI can not handle more then " << MAX_NUM_LINES << " lines." << endl;
			exit(EXIT_FAILURE);
		}
	}
}

void JS_Dropdown::outputToJS(void)
{
	if(debug)
		cout << "Writting out the JS file to cout." << endl << endl;

	int initalTabSize = 1, numOfButtons=1;

	cout << "document.write('\\" << endl;
	printWithTabs(initalTabSize-1, "\\");
	printWithTabs(initalTabSize-1, "<div class=\"container\">\\");
	printWithTabs(initalTabSize,  "<h3>"+title+"</h3>\\");
	printWithTabs(initalTabSize,  "<button type=\"button\" class=\"btn btn-link\" data-toggle=\"collapse\" data-target=\"#collapse_button_"+itos(numOfButtons)+"\"><b><i style=\"font-size:70%;\" class=\"glyphicon glyphicon-chevron-down\"></i> "+content[0]+"</b></button>\\");
	printWithTabs(initalTabSize,  "<div id=\"collapse_button_"+itos(numOfButtons)+"\" class=\"collapse\">\\");
	printWithTabs(initalTabSize+1, "<ol>\\");

	numOfButtons++;

	for(int i=1; i<numOfLines; i++)
	{
		if(numOfTabs[i]==0)
		{
			for(int j=numOfTabs[i-1]-numOfTabs[i]; j>1; j--)
				printWithTabs(initalTabSize+numOfTabs[i]+j, "</ul>\\");

			printWithTabs(initalTabSize+1, "</ol>\\");
			printWithTabs(initalTabSize, "</div>\\");
			printWithTabs(initalTabSize, "<br>\\");
			printWithTabs(initalTabSize,  "<button type=\"button\" class=\"btn btn-link\" data-toggle=\"collapse\" data-target=\"#collapse_button_"+itos(numOfButtons)+"\"><b><i style=\"font-size:70%;\" class=\"glyphicon glyphicon-chevron-down\"></i>  "+content[i]+"</b></button>\\");
			printWithTabs(initalTabSize,  "<div id=\"collapse_button_"+itos(numOfButtons)+"\" class=\"collapse\">\\");
			printWithTabs(initalTabSize+1, "<ol>\\");
			numOfButtons++;
		}
		else if(numOfTabs[i] > numOfTabs[i-1] && numOfTabs[i-1] != 0)
			printWithTabs(initalTabSize+numOfTabs[i-1]+1, "<ul>\\");
		else if(numOfTabs[i] < numOfTabs[i-1])
		{
			for(int j=numOfTabs[i-1]-numOfTabs[i]; j>0; j--)
				printWithTabs(initalTabSize+numOfTabs[i]+j, "</ul>\\");
		}

		if(numOfTabs[i]!=0)
			printWithTabs(initalTabSize+numOfTabs[i]+1, "<li>"+content[i]+"</li>\\");
	}
	for(int j=numOfTabs[numOfLines-1]; j>1; j--)
		printWithTabs(initalTabSize+j, "</ul>\\");

	printWithTabs(initalTabSize+1, "</ol>\\");
	printWithTabs(initalTabSize, "</div>\\");
	printWithTabs(initalTabSize-1, "</div>\\");
	printWithTabs(initalTabSize-1, "\\");
	cout << "');" << endl;
}

void JS_Dropdown::printWithTabs(int n, const string& s)
{
	for(int i=0; i<n; i++)
		cout << "\t";

	for(int i=0; i<s.length(); i++) {
		if(s[i] == '\'')
			cout << "\\\'";
		else
			cout << s[i];
	}
	cout << endl;
}

string JS_Dropdown::itos(int i)
{
	stringstream s;
	s << i;
	return s.str();
}

int main()
{
	JS_Dropdown js_dropdown;
	js_dropdown.readInLines();
	js_dropdown.outputToJS();

	return 0;
}
