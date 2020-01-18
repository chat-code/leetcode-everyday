#include <string>
#include <array>
#include <vector>
struct tire
{
    tire()
    {
        memset(table.data(), 0, sizeof(tire *) * 26);
    }
    ~tire() = default;
    ::std::array<tire *, 26> table;
    int index = -1;
};

class Solution
{
public:
    ::std::vector<::std::vector<char>> board;
    ::std::vector<::std::string> words;
    ::std::vector<::std::string> findWords(::std::vector<::std::vector<char>> &board, ::std::vector<::std::string> &words)
    {

        ::std::vector<::std::string> ans;
        this->board = move(board);
        this->words = move(words);
        auto root = maketire();
        for (auto i = 0; i != this->board.size(); ++i)
            for (auto j = 0; j != this->board[i].size(); ++j)
                find(root, ans, i, j);
        return ans;
    }
    void find(tire *root, ::std::vector<::std::string> &ans, int x, int y)
    {
        auto it = board[x][y] - 'a';
        if (board[x][y] == ' ' || root->table[it] == nullptr)
            return;
        root = root->table[it];
        if (root->index != -1 && words[root->index].size() != 0)
            ans.emplace_back(move(words[root->index]));
        auto c = board[x][y];
        board[x][y] = ' ';
        if (x > 0)
            find(root, ans, x - 1, y);
        if (y > 0)
            find(root, ans, x, y - 1);
        if (x < board.size() - 1)
            find(root, ans, x + 1, y);
        if (y < board[x].size() - 1)
            find(root, ans, x, y + 1);
        board[x][y] = c;
    }
    tire *maketire()
    {
        auto root = new tire();
        for (auto i = 0; i != words.size(); ++i)
        {
            auto ptr = root;
            for (auto ch : words[i])
            {
                if (ptr->table[ch - 'a'] == nullptr)
                    ptr->table[ch - 'a'] = new tire();
                ptr = ptr->table[ch - 'a'];
            }
            ptr->index = i;
        }
        return root;
    }
};