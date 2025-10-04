class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // construct two maps s->t and t->s
        map<char,char> mppST, mppTS;
        for(int i=0;i<s.length();i++){
            char sh = s[i], th = t[i];
            // check if sh is already mapped or not
            if(mppST.count(sh) && mppST[sh]!=th)
                return false; // present and not mapped to correct one
            // check the same for th
            if(mppTS.count(th) && mppTS[th]!=sh)
                return false;
            // now map them
            mppST[sh] = th;
            mppTS[th] = sh;
        }
        return true;
    }
};
