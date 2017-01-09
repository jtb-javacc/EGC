/*
 * ASTMyID.h
 *
 *  Created on: 28 mars 2014
 *      Author: FrancisANDRE
 */

#ifndef ASTMYID_H_
#define ASTMYID_H_
#include "EG4Visitors.h"
#include "SimpleNode.h"

namespace EG4 {
class ParserVisitor;

class ASTMyID : public EG4Visitors, public SimpleNode {
private:
	JAVACC_STRING_TYPE name;
public:
	ASTMyID(int i);
	ASTMyID(Parser *p, int id);
	virtual ~ASTMyID();

	void setName(JAVACC_STRING_TYPE image);
	JAVACC_STRING_TYPE toString() const;

	int x;


	/** Accept the visitor. **/
public:
	virtual void* jjtAccept(ParserVisitor *visitor, void * data) const;


    void accept(EG4Visitors::MyConstVisitor& v)
    {
        v.visit(*this);
    }
};

} /* namespace EG4 */

#endif /* ASTMYID_H_ */
