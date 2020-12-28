# 9_1

class student():
    def __init__(self, name, id, major, learn, score):
        self.name = name
        self.id = id
        self.major = major
        self.learn = learn
        self.score = score
        self.avg_score = sum(score.values())/len(learn)

    def get_lec_count(self):
        return len(self.learn)

    def get_summary(self):
        print("name",self.name)
        print("id",self.id)
        print("major", self.major)

    def change_major(self,major):
        self.major = major

std = student(name="신의현", id=2015311021,major="시경", learn=["객체", "생관"], score={"객체":100, "생관":90})

std.get_summary()
print(std.avg_score)
print(std.get_lec_count())
std.change_major("컴공")
std.get_summary()
