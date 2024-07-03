namespace MonsterType {
enum MonsterType {
    kOrc,
    kGoblin,
    kTroll,
    kOgre,
    kSkeleton,

};
}

int main() {
    int k;
    MonsterType::MonsterType player{MonsterType::kGoblin};
}
