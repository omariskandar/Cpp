/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiskanda <oiskanda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:29:48 by oiskanda          #+#    #+#             */
/*   Updated: 2025/09/05 17:19:22 by oiskanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

static bool isOperator(const std::string &token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

static int do_op(int num1, int num2, const std::string &op) {
    if (op == "+") return num1 + num2;
    if (op == "-") return num1 - num2;
    if (op == "*") return num1 * num2;
    if (op == "/") {
        if (num2 == 0)
            throw std::runtime_error("Division by zero");
        return num1 / num2;
    }
    throw std::runtime_error("Unknown operator");
}

int evaluateRPN(const std::string &expr) {
    std::stack<int> st;
    std::stringstream ss(expr);
    std::string token;

    while (ss >> token)
	{
        if (isOperator(token))
		{
            if (st.size() < 2)
                throw std::runtime_error("Invalid RPN expression");
            int num2 = st.top(); st.pop();
            int num1 = st.top(); st.pop();
            int result = do_op(num1, num2, token);
            st.push(result);
        }
        else if (token.size() == 1 && isdigit(token[0]))
		{
            int value = token[0] - '0';
            st.push(value);
        }
        else
            throw std::runtime_error("Invalid token (must be single digit or operator): " + token);
    }
    if (st.size() != 1)
        throw std::runtime_error("Invalid RPN expression");
    return st.top();
}
