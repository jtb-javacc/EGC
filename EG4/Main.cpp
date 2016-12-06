#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "Parser.h"
#include "EG4DumpVisitor.h"
#include "ParseException.h"
#include "MyErrorHandler.h"

using namespace std;
using namespace EG4;
//struct PrintVisitor: EG4Visitors::MyConstVisitor
//{
//    void visit(const ASTMyID& x)
//    {
//        std::cout << "I am a MyDouble: " << x.x << std::endl;
//    }
//
//    void visit(const ASTMyOtherID& x)
//    {
//        std::cout << "I am a MyInt: " << x.x << std::endl;
//    }
//};

JAVACC_STRING_TYPE ReadFileFully(char *file_name) {
//	JAVACC_STRING_TYPE s;
//#if WIDE_CHAR
//	wifstream in;
//#else
//	ifstream in;
//#endif
//	in.open(file_name, ios::in);
//	// Very inefficient.
//	while (!in.eof()) {
//		s += in.get();
//	}
//	return s;
	return "(1 + 2) * (a + b);\n";
}

int main(int argc, char** argv) {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	cout << "Reading from standard input..." << endl;
	JAVACC_STRING_TYPE s = ReadFileFully(argv[1]);
	try {
		CharStream *stream = new CharStream(s.c_str(), s.size() - 1, 1, 1);
		ParserTokenManager *scanner = new ParserTokenManager(stream);
		Parser parser(scanner);
		parser.setErrorHandler(new MyErrorHandler());
		ASTStart* n = parser.Start();
//		parser.jjtree.peekNode();
//		n->dump("");
		EG4DumpVisitor eg4dv;
		eg4dv.visit(n, NULL);
		cout << "thank you." << endl;
	} catch (const ParseException& e) {

	}
//	SimpleNode *root = (SimpleNode*) parser.jjtree.peekNode();
//	if (root) {
//		JAVACC_STRING_TYPE buffer;
//	#if WIDE_CHAR
//		//root->dumpToBuffer(L" ", L"\n", &buffer);
//		//wcout << buffer << "\n";
//		root->dump(L" ");
//	#else
//		root->dumpToBuffer(" ", "\n", &buffer);
//		printf("%s\n", buffer.c_str());
//	#endif
	return 0;
}

