/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wschafer <wschafer@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 11:12:41 by wschafer          #+#    #+#             */
/*   Updated: 2026/04/02 12:43:57 by wschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <bits/stdc++.h>
#include <string>

int main(int argc, char **argv) {

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	else
	{
		for (int i = 1; argv[i]; i++)
		{
			for (int j = 0; argv[i][j]; j++)
			{
				argv[i][j] = std::toupper(argv[i][j]);
			}
			std::cout << argv[i];
		}
	}
	std::cout << "\n";
	return 0;
}