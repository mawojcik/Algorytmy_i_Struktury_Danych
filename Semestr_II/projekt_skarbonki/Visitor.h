template <typename T>
class Visitor {
public:
    virtual void Visit(T& element);
    virtual bool IsDone() const { return false; }
};