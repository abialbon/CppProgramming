#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
using namespace std;

bool is_tag(string s)
{
    if (s.size() < 2) return false;
    return s[0] == '<' && s[1] != '/';
}

bool is_end_tag(string s)
{
    if (s.size() < 3) return false;
    return s[0] == '<' && s[1] == '/';
}

string tag_name(string s)
{
    if (s.find(">") == string::npos)
    {
        return s.substr(1);
    } else {
        return s.substr(1, s.length() - 2);
    }
}

string extract_value(string s)
{
    if (s[s.length() - 1] == '>')
    {
        return s.substr(1, s.length() - 3);
    } else
    {
        return s.substr(1, s.length() - 2);
    }
}

bool is_selector(string s)
{
    return (s.find('~') == string::npos);
}

string get_attribute_name(string s)
{
    int pos = (int) s.find('~');
    return s.substr(pos + 1);
}

string get_tag_name(string s)
{
    int pos = (int) s.find('~');
    return s.substr(0, pos);
}

struct node {
    string name;
    node* parent;
    vector<node*> tags;
    unordered_map<string, string> attributes;
};

node* find_childnode(node* curr_node, string tag_name)
{
    for (auto i = 0; i < curr_node->tags.size(); ++i)
    {
        if (!tag_name.compare((curr_node->tags[i]->name)))
        {
            return curr_node->tags[i];
        }
    }
    return nullptr;
}

int main() {
    int n, q;
    scanf("%d %d\n", &n, &q);
    node root;
    root.name = "root";

    node* current_node = &root;
    for (int i = 0; i < n; ++i)
    {
        string stp;
        getline(cin, stp);

        string token;
        stringstream ss(stp);
        char delim = ' ';
        string previous;
        bool expecting_value = false;
        while (getline(ss, token, delim))
        {
            if (is_tag(token))
            {
                node *temp = new node();
                temp->name = tag_name(token);
                temp->parent = current_node;
                current_node->tags.push_back(temp);
                current_node = temp;
            }

            if (expecting_value)
            {
                current_node->attributes[previous] = extract_value(token);
                expecting_value = false;
                continue;
            }

            if (!token.compare("="))
            {
                expecting_value = true;
            } else {
                previous = token;
            }

            if (is_end_tag(token))
            {
                current_node = current_node->parent;
            }
        }
    }

    for (int i = 0; i < q; ++i)
    {
        node* selected_node = &root;
        string stp;
        getline(cin, stp);

        string token;
        stringstream ss(stp);
        char delim = '.';
        while (getline(ss, token, delim))
        {
            if (is_selector(token))
            {
                if (find_childnode(selected_node, token) == nullptr)
                {
                    cout << "Not Found!" << endl;
                    break;
                } else
                {
                    selected_node = find_childnode(selected_node, token);
                }
            } else
            {
                string selector = get_tag_name(token);
                if (find_childnode(selected_node, selector) == nullptr)
                {
                    cout << "Not Found!" << endl;
                    break;
                } else
                {
                    selected_node = find_childnode(selected_node, selector);
                }
                string attribute = get_attribute_name(token);
                string value = selected_node->attributes[attribute];
                if (value != "")
                {
                    cout << value << endl;
                } else
                {
                    cout << "Not Found!" << endl;
                }
            }
        }
    }
    return 0;
}
