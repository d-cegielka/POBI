//
// Created by Kamil Zarych <224546@edu.p.lodz.pl> on 11.12.2019.
//

#ifndef POBIPROJECT_REPOSITORY_H
#define POBIPROJECT_REPOSITORY_H

#include <list>
#include <iostream>
#include <memory>
#include <algorithm>

template <class T>
class Repository {
protected:
    std::list<std::shared_ptr<T>> listElements;

public:
    virtual ~Repository();

    virtual void create(const std::shared_ptr<T> &element);

    virtual void remove(const std::shared_ptr<T> &element);

    virtual std::shared_ptr<T> find(const std::string ID) const;

    virtual std::shared_ptr<T> find(const std::shared_ptr<T> &element) const;

    virtual std::list<std::shared_ptr<T>> getAll() const;

};

template<class T>
Repository<T>::~Repository() {}

template<class T>
void Repository<T>::create(const std::shared_ptr<T> &element) {
    listElements.push_back(element);
}

template<class T>
void Repository<T>::remove(const std::shared_ptr<T> &element) {
    listElements.remove(element);
}

template<class T>
std::shared_ptr<T> Repository<T>::find(const std::string ID) const {
    auto it = std::find_if(listElements.begin(), listElements.end(),
                           [&ID](const std::shared_ptr<T> &x) -> bool { return *x == ID; });
    if (it != listElements.end())
        return *it;

    return nullptr;
}

template<class T>
std::shared_ptr<T> Repository<T>::find(const std::shared_ptr<T> &element) const {
    auto it = std::find_if(listElements.begin(), listElements.end(),
                           [&element](const std::shared_ptr<T> &x) -> bool { return *x == *element; });
    if (it != listElements.end())
        return *it;

    return nullptr;
}

template<class T>
std::list<std::shared_ptr<T>> Repository<T>::getAll() const {
    return std::list<std::shared_ptr<T>>();
}

#endif //POBIPROJECT_REPOSITORY_H
