class Solution {
    int daysInMonth(int m) {
        if (m % 2 == 1 && m <= 7 || m % 2 == 0 && m >= 8)
            return 31;
        return m == 2 ? 28 : 30;
    }

public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        int aaMon = stoi(arriveAlice.substr(0, 2));
        int alMon = stoi(leaveAlice.substr(0, 2));
        int aaDate = stoi(arriveAlice.substr(3, 2));
        int alDate = stoi(leaveAlice.substr(3, 2));

        int baMon = stoi(arriveBob.substr(0, 2));
        int blMon = stoi(leaveBob.substr(0, 2));
        int baDate = stoi(arriveBob.substr(3, 2));
        int blDate = stoi(leaveBob.substr(3, 2));

        int days = 0;

        int maxArriveMon, minLeaveMon;

        if (aaMon > baMon) {
            maxArriveMon = aaMon;
            days -= (aaDate - 1);
        } 
        else {
            maxArriveMon = baMon;
            days -= aaMon < baMon ? (baDate - 1) : (max(aaDate, baDate) - 1);
        }

        if (alMon < blMon) {
            minLeaveMon = alMon;
            days -= (daysInMonth(alMon) - alDate);
        } 
        else {
            minLeaveMon = blMon;
            if(alMon == blMon) {
                days -= (daysInMonth(alMon) - min(alDate, blDate));
            }
            else days -= (daysInMonth(blMon) - blDate);
        }

        for (int i = maxArriveMon; i <= minLeaveMon; i++) {
            days += daysInMonth(i);
        }

        return max(days, 0);
    }
};