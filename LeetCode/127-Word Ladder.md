英文链接: https://leetcode.com/problems/word-ladder/  
中文链接: https://leetcode-cn.com/problems/word-ladder/

```
class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		// 不要写成 unordered_set<string> dict;
		unordered_set<string> dict(wordList.begin(), wordList.end());
		unordered_map<string, int> m;

		queue<string> q;
		q.push(beginWord);
		// 不要遗漏这一步
		m[beginWord] = 1;

		while (!q.empty())
		{
			string word = q.front();
			q.pop();

			for (int i = 0; i < word.size(); ++i)
			{
				string newWord = word;
				for (char ch = 'a'; ch <= 'z'; ++ch)
				{
					newWord[i] = ch;

					if (dict.count(newWord) > 0)
					{
						if (newWord == endWord)
						{
							// 注意是 return m[word] + 1; 而不是 return m[newWord] + 1;
							return m[word] + 1;
						}
						else if (m.count(newWord) == 0)
						{
							q.push(newWord);
							m[newWord] = m[word] + 1;
						}
					}
				}
			}
		}

		return 0;
	}
};
```
