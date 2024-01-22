
class Temperature {
private:
    double tempK;
public:
    Temperature();

    Temperature(double temperK);

    double getKelvin();

    double getCelsius();

    double getFahrenheit();

    void setTemp(double temp, char type);

    void setKelvin(double temp);

    void setCelsius(double temp);

    void setFahrenheit(double temp);

    void add(Temperature &temp);
};