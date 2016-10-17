class BigKahuna: public Node {
    private:
        const int greetingPin = 1;
        const int dispensePin = 2;
        const int lightPin = 3;
        int partyTime = 0;
    public:
        void greeting();
        void dispense();
        void dispenseOverride();
        void eyesOn();
        void eyesOff();
        void startParty();
        void stopParty();
};