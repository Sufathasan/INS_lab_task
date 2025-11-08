#include <bits/stdc++.h>
using namespace std;

// Function to display frequency table
void analyzeFrequency(const string &text, const string &label) {
    unordered_map<char, int> freq;
    int total = 0;

    // Count each alphabet
    for (char c : text) {
        c = tolower(c);
        if (c >= 'a' && c <= 'z') {
            freq[c]++;
            total++;
        }
    }

    // Move to vector for sorting
    vector<pair<char, int>> sorted(freq.begin(), freq.end());
    sort(sorted.begin(), sorted.end(), [](auto &a, auto &b) {
        return a.second > b.second;
    });

    cout << "\n" << label << "\n";
    cout << "Letter | Count | Percentage\n";
    cout << "-------|--------|-----------\n";

    for (auto &p : sorted) {
        cout << "   " << p.first << "   |  " << setw(4) << p.second
             << "   |  " << fixed << setprecision(2)
             << (p.second * 100.0 / total) << "%\n";
    }
}

// Decrypt using substitution key map
string applySubstitution(const string &cipher, const map<char, char> &key) {
    string plain = cipher;
    for (char &c : plain) {
        char lower = tolower(c);
        if (key.count(lower)) {
            char newChar = key.at(lower);
            c = isupper(c) ? toupper(newChar) : newChar;
        }
    }
    return plain;
}

int main() {
    cout << "======= SUBSTITUTION CIPHER DECODER =======\n";

    // Cipher text 1
    string cipher1 =
        "af p xpkcaqvnpk pfg, af ipqe qpri, gauuikifc tpw, ceiri udvk tiki "
        "afgarxifrphni cd eao--wvmd popkwn, hiqpvri du ear jvaql "
        "vfgikrcpfgafm du cei xkafqaxnir du xrwqedearcdkw pfg du ear "
        "aopmafpcasi xkdhafmr afcd fit pkipr. ac tpr qdoudkcafm cd lfdt cepc "
        "au pfwceafm epxxifig cd ringdf eaorinu hiudki cei opceiopcaqr du cei "
        "uaing qdvng hi qdoxnicinw tdklig dvc--pfg edt rndtnw ac xkdqiigig, "
        "pfg edt odvfcpafdvr cei dhrcpqnir--ceiki tdvng pc niprc kiopaf dfi "
        "mddg oafg cepc tdvng qdfcafvi cei kiripkqe";

    // Cipher text 2
    string cipher2 =
        "aceah toz puvg vcdl omj puvg yudqecov, omj loj auum klu thmjuv hs klu "
        "zlcvu shv zcbkg guovz, upuv zcmdu lcz vuwovroaeu jczoyyuovomdu omj "
        "qmubyudkuj vukqvm. klu vcdluz lu loj avhqnlk aodr svhw lcz kvopuez "
        "loj mht audhwu o ehdoe eunumj, omj ck toz yhyqeoveg auecupuj, "
        "tlokupuv klu hej sher wcnlk zog, klok klu lcee ok aon umj toz sqee "
        "hs kqmmuez zkqssuj tckl kvuozqvu. omj cs klok toz mhk umhqnl shv "
        "sowu, kluvu toz oezh lcz yvhehmnuj pcnhqv kh wovpue ok. kcwu thvu hm, "
        "aqk ck zuuwuj kh lopu eckkeu ussudk hm wv. aonncmz. ok mcmukg lu toz "
        "wqdl klu zowu oz ok scskg. ok mcmukg-mcmu klug aunom kh doee lcw "
        "tuee-yvuzuvpuj; aqk qmdlomnuj thqej lopu auum muovuv klu wovr. kluvu "
        "tuvu zhwu klok zlhhr klucv luojz omj klhqnlk klcz toz khh wqdl hs o "
        "nhhj klcmn; ck zuuwuj qmsocv klok omghmu zlhqej yhzzuzz (oyyovumkeg) "
        "yuvyukqoe ghqkl oz tuee oz (vuyqkujeg) cmubloqzkcaeu tuoekl. ck tcee "
        "lopu kh au yocj shv, klug zocj. ck czm'k mokqvoe, omj kvhqaeu tcee "
        "dhwu hs ck! aqk zh sov kvhqaeu loj mhk dhwu; omj oz wv. aonncmz toz "
        "numuvhqz tckl lcz whmug, whzk yuhyeu tuvu tceecmn kh shvncpu lcw lcz "
        "hjjckcuz omj lcz nhhj shvkqmu. lu vuwocmuj hm pczckcmn kuvwz tckl lcz "
        "vueokcpuz (ubduyk, hs dhqvzu, klu zodrpceeuaonncmzuz), omj lu loj "
        "womg juphkuj ojwcvuvz owhmn klu lhaackz hs yhhv omj qmcwyhvkomk "
        "sowcecuz. aqk lu loj mh dehzu svcumjz, qmkce zhwu hs lcz ghqmnuv "
        "dhqzcmz aunom kh nvht qy. klu uejuzk hs kluzu, omj aceah'z sophqvcku, "
        "toz ghqmn svhjh aonncmz. tlum aceah toz mcmukg-mcmu lu ojhykuj svhjh "
        "oz lcz lucv, omj avhqnlk lcw kh ecpu ok aon umj; omj klu lhyuz hs klu "
        "zodrpceeu-aonncmzuz tuvu scmoeeg jozluj. aceah omj svhjh loyyumuj kh "
        "lopu klu zowu acvkljog, zuykuwauv 22mj. ghq loj aukkuv dhwu omj ecpu "
        "luvu, svhjh wg eoj, zocj aceah hmu jog; omj klum tu dom dueuavoku "
        "hqv acvkljog-yovkcuz dhwshvkoaeg khnukluv. ok klok kcwu svhjh toz "
        "zkcee cm lcz ktuumz, oz klu lhaackz doeeuj klu cvvuzyhmzcaeu "
        "ktumkcuz auktuum dlcejlhhj omj dhwcmn hs onu ok klcvkg-klvuu";

    cout << "\n\n---- CIPHER 1 ANALYSIS ----\n";
    analyzeFrequency(cipher1, "CIPHER-1 FREQUENCY TABLE");

    map<char, char> map1 = {
        {'i', 'e'}, {'a', 'i'}, {'p', 'a'}, {'u', 'o'}, {'c', 't'},
        {'e', 'h'}, {'d', 'f'}, {'v', 'u'}, {'g', 'd'}, {'f', 'n'},
        {'k', 'r'}, {'q', 'c'}, {'n', 'l'}, {'h', 'b'}, {'t', 'w'},
        {'r', 's'}, {'o', 'm'}, {'w', 'y'}, {'l', 'k'}, {'m', 'g'},
        {'x', 'p'}, {'j', 'q'}, {'b', 'v'}, {'s', 'z'}, {'y', 'x'},
        {'z', 'j'}
    };

    cout << "\nDecrypted Cipher-1:\n\n";
    cout << applySubstitution(cipher1, map1) << "\n";

    cout << "\n\n---- CIPHER 2 ANALYSIS ----\n";
    analyzeFrequency(cipher2, "CIPHER-2 FREQUENCY TABLE");

    map<char, char> map2 = {
        {'u', 'e'}, {'v', 't'}, {'e', 'a'}, {'c', 's'}, {'d', 'h'},
        {'m', 'r'}, {'s', 'i'}, {'n', 'w'}, {'h', 'n'}, {'y', 'd'},
        {'o', 'g'}, {'z', 'b'}, {'f', 'l'}, {'l', 'o'}, {'i', 'f'},
        {'a', 'v'}, {'b', 'u'}, {'p', 'y'}, {'g', 'm'}, {'k', 'p'},
        {'t', 'c'}, {'x', 'k'}, {'r', 'x'}, {'q', 'z'}, {'j', 'q'},
        {'w', 'j'}
    };

    cout << "\nDecrypted Cipher-2:\n\n";
    cout << applySubstitution(cipher2, map2) << "\n";

    return 0;
}
