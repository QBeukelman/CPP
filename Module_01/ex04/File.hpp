/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 17:04:54 by quentinbeuk       #+#    #+#             */
/*   Updated: 2025/04/11 11:20:46 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class File {
	private:
		std::string		fileName;
		std::string		fileData;

	public:
		File();
		File(const std::string& fileName, std::string fileData);
		~File();

		void				setFileName(const std::string& newFileName);
		std::string			getFileName() const;
		
		void				setFileData(const std::string& newFileData);
		std::string			getFileData() const;

		bool				openFile(const std::string& fileName);
		bool				writeFile(const std::string& fileName, const std::string& newFileData);
};
