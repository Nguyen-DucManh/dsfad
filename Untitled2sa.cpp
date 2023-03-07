string combineWordsFromFile(const char fileName[]) {
    vector<string> words;
    ifstream infile(fileName);
    string word;

    while (infile >> word) {
        words.push_back(word);
    }

    sort(words.begin(), words.end(), greater<string>());

    string s;
    for (const auto& w : words) {
        s += w + " ";
    }

    if (!s.empty()) {
        s.pop_back();
    }

    return s;
}
