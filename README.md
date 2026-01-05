# How to use hunspell(from vcpkg) with QT on windows

# Usage
`vcpkg install hunspell`
modify `.pro` file to add hunspell library paths

# Cause of problem
hunspell.hxx
```cpp
  bool spell(const std::string& word, int* info = NULL, std::string* root = NULL);
  H_DEPRECATED int spell(const char* word, int* info = NULL, char** root = NULL);
```

the method which return int works but the method which return bool does not work as per my testing.
`int spell(const char* word ,...)` but be crafted carefully, otherwise it will not not work too

# Expected output in console
```
"C:/Users/admin/Documents/hunspell-demo/en_US.aff"
"C:/Users/admin/Documents/hunspell-demo/en_US.dic"
AFF exists: true
DIC exists: false
spell  "hello" : 1
spell  "world" : 1
spell  "test" : 1
spell  "gkfjgkdfjgkdj" : 0
spell  "xyzabc" : 0
```
