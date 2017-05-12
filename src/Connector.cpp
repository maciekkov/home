#include "Connector.h"

Connector::Connector(const string& _key,unsigned int _index)
{
    this->key=_key;
    this->index=_index;
}

Connector::~Connector()
{
    //dtor
}
