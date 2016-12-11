#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <stdlib.h>

#include "gen/JavaCC.h"
#include "gen/ParserTokenManager.h"
#include "gen/ParseException.h"
#include "gen/Parser.h"

using namespace std;
using namespace EG1;

JAVACC_STRING_TYPE ReadFileFully(char *file_name) {
	return "(1 + 2) * (a + b);\n";
}

int main(int argc, char** argv) {
	JAVACC_STRING_TYPE s = ReadFileFully(argv[1]);
	try {
		CharStream *stream = new CharStream(s.c_str(), s.size() - 1, 1, 1);
		ParserTokenManager *scanner = new ParserTokenManager(stream);
		Parser parser(scanner);
//		parser.setErrorHandler(new MyErrorHandler());
		SimpleNode* n = parser.Start();
//		parser.jjtree.peekNode();
		n->dump("");
//		DumpVisitor eg4dv;
//		eg4dv.visit(n, NULL);
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

