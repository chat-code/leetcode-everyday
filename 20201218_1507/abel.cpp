class Solution {
public:
    string reformatDate(string date) {
      stringstream ss(date);
      string day, month, year, res;
      ss >> day >> month >> year;
      res = year + "-";

      day = day.substr(0, day.size() - 2);
      if (day.size() < 2) day = "0" + day;

      vector<string> months = {
        "", "Jan", "Feb", "Mar", 
        "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
      int monthi = 0;
      for (int i = 1; i < months.size(); ++i) {
        if (months[i] == month) { monthi = i; break; }
      }
      
      month = to_string(monthi);
      if (month.size() < 2) month = "0" + month;

      res = res + month + "-" + day;
      return res;
    }
};
