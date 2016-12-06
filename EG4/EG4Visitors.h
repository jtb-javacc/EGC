/*
 * EG4Visitors.h
 *
 *  Created on: 29 mars 2014
 *      Author: FrancisANDRE
 */

#ifndef EG4VISITORS_H_
#define EG4VISITORS_H_
#include <ConstVisitor.h>

namespace EG4 {
class ASTMyOtherID;
class ASTMyID;

class EG4Visitors {
public:
	EG4Visitors();
	virtual ~EG4Visitors();
    typedef ConstVisitor<ASTMyID, ASTMyOtherID> MyConstVisitor;

    virtual void accept(MyConstVisitor&) = 0;
};

} /* namespace EG4 */

#endif /* EG4VISITORS_H_ */
