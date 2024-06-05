/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:15:32 by mtigunit          #+#    #+#             */
/*   Updated: 2023/08/17 12:25:44 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/* **************************************** */
/*                Data class                */
/* **************************************** */

class Data {
	private:
		int	_data;
	public:
		Data();
		Data(int data);
		Data(const Data& copy);
		Data& operator=(const Data& src);
		~Data();
		int	getData( void ) const;
};
