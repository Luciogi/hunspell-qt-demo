#include <iostream>
#include <nuspell/dictionary.hxx>
#include <nuspell/finder.hxx>

using namespace std;

void main()
{
	auto dict = nuspell::Dictionary();
    auto dict_path = std::filesystem::path("C:/Users/admin/AppData/Local/hunspell/en_US.aff");
    cout << "dict: " << dict_path.generic_string();

    try {
        dict.load_aff_dic(dict_path);
    }
    catch (const nuspell::Dictionary_Loading_Error &e) {
        cerr << e.what() << '\n';
        return;
    }

    auto word = "word";
    cout << word << "? " << dict.spell(word);
}