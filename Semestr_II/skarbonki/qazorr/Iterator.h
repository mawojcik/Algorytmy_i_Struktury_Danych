template <typename T>
class Iterator
{
public:
    Iterator(){;}
    virtual ~Iterator(){}
    virtual bool IsDone() const = 0;
    virtual T& operator*() = 0;
    virtual void operator++() = 0;
};