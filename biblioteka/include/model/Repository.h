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
    std::list<T> listElements;

public:
    virtual ~Repository();

    virtual void create(const T &element);

    virtual void remove(const T &element);

    virtual T find(const std::string ID) const;

    virtual T find(const T &element) const;

    virtual std::list<T> getAll() const;

};

template<class T>
void Repository<T>::create(const T &element) {
    listElements.push_back(element);
}

template<class T>
Repository<T>::~Repository() {}

template<class T>
T Repository<T>::find(const std::string ID) const {
    for(auto element:listElements)
        if(element->getId() == ID)
            return element;

    return nullptr;
}

template<class T>
T Repository<T>::find(const T &element) const {
    for(auto el:listElements)
        if(el->getId() == element->getId())
            return el;

    return nullptr;
}


template<class T>
void Repository<T>::remove(const T &element) {
    listElements.remove(element);
}

template<class T>
std::list<T> Repository<T>::getAll() const {
    return std::list<T>();
}


#endif //POBIPROJECT_REPOSITORY_H
