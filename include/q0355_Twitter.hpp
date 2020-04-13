#include "iostream"
#include "vector"
#include "map"


class User {
private:
    int id_user;
public:
    std::vector<int> followers;//    关注用户 Id列表
    std::vector<int> followees;//    关注我的用户 Id 列表
    std::map<int, int> top10Tweets;//我的推文前十条{推文时间:推文Id}
public:

//    方法：
//    1.关注
    void follow(int id) {
        followers.push_back(id);
    }

//    2.取关
    void unfollow(int id) {
        for (std::vector<int>::iterator it = followers.begin(); it != followers.end();) {
            if (*it == id) {
                it = followers.erase(it);
            } else {
                ++it;
            }
        }
    }

//    3.被关注
    void followed(int id) {
        followees.push_back(id);
    }

//    4.被取关
    void unfollowed(int id) {
        for (std::vector<int>::iterator it = followees.begin(); it != followees.end();) {
            if (*it == id) {
                it = followees.erase(it);
            } else {
                ++it;
            }
        }
    }

//    5.压入推文
    void twit(int time, int id_tw);

};

void User::twit(int time, int id_tw) {
    top10Tweets[time] = id_tw;
    if (top10Tweets.size() > 10) top10Tweets.erase(top10Tweets.begin());
}

class Twitter {
private:
    //map:{用户 Id:用户类}
    std::map<int, User> users;
    //当前最新推文时间
    int time;
public:
    /** Initialize your data structure here. */
    Twitter() {
        time = 0;
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
//        创建推文（用户 Id,推文 Id)：将推文推至该用户，包括时间信息
        if (users.find(userId) == users.end()) {
            User temp;
            users[userId] = temp;
        }
        users[userId].twit(time++, tweetId);
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    std::vector<int> getNewsFeed(int userId) {
//        把所有该用户与该用户关注 Id 的前十条取出，然后取总的前十条
        std::map<int, int> temp = users[userId].top10Tweets;
        std::vector<int> rst;
//
        for (std::vector<int>::iterator it = users[userId].followers.begin();
             it != users[userId].followers.end(); it++) {
            merge(users[*it].top10Tweets.begin(), users[*it].top10Tweets.end(), temp.begin(), temp.end(),
                  inserter(temp, temp.begin()));
        }
        int count = 1;
        for (std::map<int, int>::reverse_iterator rit = temp.rbegin(); rit != temp.rend(); rit++) {
            rst.push_back(rit->second);
            if (count == 10)break;
            count++;
        }
        return rst;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (users.find(followerId) == users.end()) {
            User temp;
            users[followerId] = temp;
        }
        if (users.find(followeeId) == users.end()) {
            User temp;
            users[followeeId] = temp;
        }
        users[followerId].follow(followeeId);
        users[followeeId].followed(followerId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (users.find(followerId) == users.end()||users.find(followeeId) == users.end()) return;
        users[followerId].unfollow(followeeId);
        users[followeeId].unfollowed(followerId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */