#include <fstream>
using namespace std;
class RelationshipMapping {
private:
    struct Relation {
        string entity1;
        string entity2;
    };

    Relation* relationships;
    int capacity;
    int size;

    void resize() {
        capacity *= 2;
        Relation* newRelationships = new Relation[capacity];
        for (int i = 0; i < size; ++i) {
            newRelationships[i] = relationships[i];
        }
        delete[] relationships;
        relationships = newRelationships;
    }

public:
    RelationshipMapping() {
        capacity = 10;
        size = 0;
        relationships = new Relation[capacity];
    }

    ~RelationshipMapping() {
        delete[] relationships;
    }

    void addRelation(string entity1, string entity2) {
        if (size == capacity) {
            resize();
        }
        relationships[size].entity1 = entity1;
        relationships[size].entity2 = entity2;
        size++;
    }

    bool findRelation(string entity1, string entity2) {
        for (int i = 0; i < size; i++) {
            if ((relationships[i].entity1 == entity1 && relationships[i].entity2 == entity2) ||
                (relationships[i].entity1 == entity2 && relationships[i].entity2 == entity1)) {
                return true;
            }
        }
        return false;
    }

    void saveToFile(string filename) {
        ofstream outFile(filename, ios::app);
        for (int i = 0; i < size; i++) {
            outFile << relationships[i].entity1 << ";" << relationships[i].entity2 << "\n";
        }
        outFile.close();
    }
};
