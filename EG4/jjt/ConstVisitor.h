/*
 * Visitor.h
 *
 *  Created on: 22 mars 2014
 *      Author: FrancisANDRE
 */

#ifndef CONSTVISITOR_H_
#define CONSTVISITOR_H_

// Forward declaration (1st part)
template<typename... Types>
class ConstVisitor;

// Declaration (2nd part)
template<typename First, typename... Types>
class ConstVisitor<First, Types...>: ConstVisitor<Types...>
{
public:
	virtual  ~ConstVisitor();
	using ConstVisitor<Types...>::visit;
    virtual void visit(const First&) = 0;
};

// Specialized for one (3rd part)
template<typename First>
class ConstVisitor<First>
{
public:
	virtual  ~ConstVisitor();
    virtual void visit(const First&) = 0;
};



#endif /* CONSTVISITOR_H_ */
