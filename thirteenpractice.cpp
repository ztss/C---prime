//p13.5
HasPtr::HasPtr(const HasPtr& h) : ps(new string (*h.ps)), i(h.i) {}
