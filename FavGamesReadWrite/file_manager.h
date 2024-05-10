#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <vector>
#include <string>

void load(std::vector<std::string>& favoriteGames, const std::string& filename);
void save(const std::vector<std::string>& favoriteGames, const std::string& filename);

#endif