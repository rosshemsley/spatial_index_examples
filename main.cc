#include <iostream>
#include <memory>
#include <vector>

#include <spatialindex/SpatialIndex.h>

using namespace std;
using namespace SpatialIndex;
using namespace SpatialIndex::RTree;

void insert_point(SpatialIndex::ISpatialIndex* index, double x, double y, size_t id) {
    double coords[] = {x, y};
    index->insertData(0, nullptr, SpatialIndex::Point(coords, 2), id);
}


class MyVisitor : public IVisitor {
  public:
    void visitNode(const INode&) {}
    void visitData(std::vector<const IData*>&) {}
    void visitData(const IData& d) { _indices.push_back(d.getIdentifier()); }

    vector<size_t>& indices() { return _indices; }

  private:
    vector<size_t> _indices;
};


int main() {
    id_type id = 0;
    unique_ptr<IStorageManager> storage(StorageManager::createNewMemoryStorageManager());
    unique_ptr<ISpatialIndex> index(createNewRTree(*storage, 0.7, 100, 100, 2, RV_RSTAR, id));

    if (!index->isIndexValid()) {
        throw runtime_error("Failed to create valid index");
    }

    insert_point(index.get(), 1.0, 2.0, 0);
    insert_point(index.get(), 2.0, 3.0, 1);
    insert_point(index.get(), 3.0, 4.0, 2);

    MyVisitor visitor;
    auto k = 3;
    double coords[] = {0, 0};
    index->nearestNeighborQuery(k, SpatialIndex::Point(coords, 2), visitor);

    cout << "Indices of 3 points near to 0, 0: " << endl;
    for (const auto index : visitor.indices()) {
        cout << index << endl;
    }

}
