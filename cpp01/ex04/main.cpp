/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omar-iskandarani <omar-iskandarani@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 01:32:55 by omar-iskand       #+#    #+#             */
/*   Updated: 2025/08/19 01:32:57 by omar-iskand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ex04/main.cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

static std::string replace_all(const std::string& text,
                               const std::string& s1,
                               const std::string& s2)
{
    if (s1.empty())
        return text; // caller should handle empty s1 as an error; safe fallback

    std::string out;
    out.reserve(text.size()); // heuristic

    std::string::size_type pos = 0;
    while (true) {
        std::string::size_type found = text.find(s1, pos);
        if (found == std::string::npos) {
            out.append(text, pos, std::string::npos); // append the rest
            break;
        }
        // copy chunk before match
        out.append(text, pos, found - pos);
        // append replacement
        out.append(s2);
        // move past the matched s1
        pos = found + s1.size();
    }
    return out;
}

int main(int argc, char** argv)
{
    if (argc != 4) {
        std::cerr << "Usage: " << (argc > 0 ? argv[0] : "./sed_is_for_losers")
                  << " <filename> <s1> <s2>\n";
        return 1;
    }

    const std::string in_name  = argv[1];
    const std::string s1       = argv[2];
    const std::string s2       = argv[3];

    if (in_name.empty()) {
        std::cerr << "Error: empty filename.\n";
        return 1;
    }
    if (s1.empty()) {
        std::cerr << "Error: s1 must be non-empty (otherwise infinite matches).\n";
        return 1;
    }

    std::ifstream ifs(in_name.c_str(), std::ios::in | std::ios::binary);
    if (!ifs) {
        std::cerr << "Error: cannot open input file: " << in_name << "\n";
        return 1;
    }

    std::ostringstream oss;
    oss << ifs.rdbuf(); // read entire file
    if (!ifs.good() && !ifs.eof()) { // read error not due to EOF
        std::cerr << "Error: failed while reading input file.\n";
        return 1;
    }
    const std::string content = oss.str();

    // Fast path: if s1 == s2, just copy
    std::string replaced;
    if (s1 == s2) {
        replaced = content;
    } else {
        replaced = replace_all(content, s1, s2);
    }

    const std::string out_name = in_name + ".replace";
    std::ofstream ofs(out_name.c_str(), std::ios::out | std::ios::binary | std::ios::trunc);
    if (!ofs) {
        std::cerr << "Error: cannot open output file: " << out_name << "\n";
        return 1;
    }

    ofs.write(replaced.c_str(), static_cast<std::streamsize>(replaced.size()));
    if (!ofs) {
        std::cerr << "Error: failed while writing output file.\n";
        return 1;
    }

    return 0;
}
