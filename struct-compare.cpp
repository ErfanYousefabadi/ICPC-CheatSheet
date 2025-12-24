struct something {
    int x;
    bool operator< (const something &b) const {
        return x < b.x;
    };
};
