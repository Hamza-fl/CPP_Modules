/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 16:35:16 by hfalati           #+#    #+#             */
/*   Updated: 2025/09/27 16:35:17 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

int main (int ac, char **av)
{
    if (ac  != 4)
    {
        std::cerr << "Usage: " << av[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }
    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];
    if (s1.empty()) {
        std::cerr << "Error: s1 connot be empty\n";
        return 1;
    }
    std::ifstream infile(filename.c_str()); // to chow the int fd = outfile.rdbuf()->fd();
    if (!infile)
    {
        std::cerr << "Error: could not open input file" << std::endl;
        return 1;
    }
    std::ofstream outfile((filename + ".replace").c_str());
    if (!outfile)
    {
        std::cerr << "Error: could not create output file" << std::endl;
        return 1;
    }
    std::string line;
    while (std::getline(infile, line))
    {
        std::size_t pos= 0;
        while ((pos = line.find(s1, pos)) != std::string::npos)
        {
            line.erase(pos, s1.length());
            line.insert(pos, s2);
            pos += s2.length();
        }
        outfile << line << std::endl;
    }
    infile.close();
    outfile.close();
    return 0;
}