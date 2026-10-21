#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <stdexcept>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <map>

class TransportException : public std::runtime_error {
public:
    explicit TransportException(const std::string& msg) : std::runtime_error(msg) {}
};
class InsufficientFundsException : public TransportException {
public: explicit InsufficientFundsException(const std::string& msg = "Insufficient funds") : TransportException(msg) {}
};
class InvalidClientDataException : public TransportException {
public: explicit InvalidClientDataException(const std::string& msg = "Invalid client data") : TransportException(msg) {}
};
class OrderNotFoundException : public TransportException {
public: explicit OrderNotFoundException(const std::string& msg = "Order not found") : TransportException(msg) {}
};
class InvalidOrderDataException : public TransportException {
public: explicit InvalidOrderDataException(const std::string& msg = "Invalid order data") : TransportException(msg) {}
};
class InvalidCargoDataException : public TransportException {
public: explicit InvalidCargoDataException(const std::string& msg = "Invalid cargo data") : TransportException(msg) {}
};
class CargoOverweightException : public TransportException {
public: explicit CargoOverweightException(const std::string& msg = "Cargo overweight") : TransportException(msg) {}
};
class VehicleOverloadException : public TransportException {
public: explicit VehicleOverloadException(const std::string& msg = "Vehicle overload") : TransportException(msg) {}
};
class VehicleNotAvailableException : public TransportException {
public: explicit VehicleNotAvailableException(const std::string& msg = "Vehicle not available") : TransportException(msg) {}
};
class DriverNotAvailableException : public TransportException {
public: explicit DriverNotAvailableException(const std::string& msg = "Driver not available") : TransportException(msg) {}
};
class InvalidLicenseException : public TransportException {
public: explicit InvalidLicenseException(const std::string& msg = "Invalid license") : TransportException(msg) {}
};
class WarehouseCapacityExceededException : public TransportException {
public: explicit WarehouseCapacityExceededException(const std::string& msg = "Warehouse capacity exceeded") : TransportException(msg) {}
};

class Accountant : public Employee{
public:
    Accountant(int id = 0, std::string n = "");
    void processPayment(Payment p);
    void generateInvoice(Order o);
    double calculateTax(double amount) const;
    void auditFinances();
};

class Address{
private:
    std::string street, city, zip, country;
    GPSPosition position;
public:    
    Address() = default;
    Address(std::string s, std::string c, std::string z, std::string cnt, double lat, double lon);
    bool isValid() const;
    std::string format() const;
};

class BankAccount {
private:
    std::string accountNumber, owner;
    double balance;
public:
    BankAccount(std::string acc = "", std::string own = "", double bal = 0);
    void deposit(double amount);
    void withdraw(double amount);
    bool transfer(std::shared_ptr<BankAccount> to, double amount);
    double getBalance() const { return balance; }
};

class Cargo{
private:
    int id;
    double weight, volume;
    std::string type, description;
public:
    Cargo(int id = 0, double w = 0, double v = 0, std::string t = "");
    double calculateShippingCost(double distance) const;
    bool isOverweight(double maxWeight) const;
    bool validate() const;
};

class Client {
private:
    int id;
    std::string name, contact;
    Address address;
    int loyaltyPoints;
public:
    Client(int id = 0, std::string n = "", std::string c = "");
    void placeOrder(Order order);
    void makePayment(Payment p);
    void updateContact(const std::string& newContact);
    void redeemPoints(int points);
};

class CompanyFinance {
private:
    double totalRevenue, totalExpenses;
public:
    CompanyFinance();
    void addRevenue(double amount);
    void addExpense(double amount);
    double calculateProfit() const;
    std::string generateReport() const;
};

class CustomerService {
private:
    std::vector<Employee> agents;
    std::vector<std::pair<Client, std::string>> tickets;
public:
    CustomerService() = default;
    void openTicket(Client client, const std::string& issue);
    bool closeTicket(int index);
    void escalate(int index);
};

class Dispatcher : public Employee {
private:
    std::string shift;
    std::vector<Order> activeOrders;
public:
    Dispatcher(int id = 0, std::string n = "");
    Vehicle assignOrder(Order order, Driver dr);
    void trackVehicle(Vehicle v);
    void handleEmergency(const std::string& description);
};

class Driver : public Employee {
private:
    DrivingLicense license;
    int experienceYears;
    double rating;
    bool available;
    Vehicle vehicle;
public:
    Driver(int id = 0, std::string n = "");
    void assignVehicle(Vehicle v);
    void completeTrip(double distance);
    void updateRating(double newRating);
    bool isAvailable() const;
};

class DrivingLicence{
private:
    std::string number, category;
    std::string issueDate, expiryDate;
public:
    DrivingLicense(std::string num, std::string cat, std::string issue, std::string expiry);
    bool isValid() const;
    void renew(std::string newExpiry);
    bool canDrive(const std::string& requiredCategory) const;
};

class Employee{
private:
    int id;
    std::string name, position, department;
    double salary;
    std::string hireDate;
public:
    Employee(int id = 0, std::string n = "", std::string pos = "", double sal = 0);
    void promote(const std::string& newPosition, double salaryIncrease);
    double calculateBonus(double performanceScore) const;
    bool isActive() const;
};

class Exeptions{};

class ExpressDelivery : public Cargo {
private:
    int priority;
    std::time_t guaranteedDeliveryTime;
public:
    ExpressDelivery(int id = 0, double w = 0, double v = 0, int p = 1);
    double calculateExpressCost() const;
    bool isUrgent() const;
    void upgradePriority();
};

class FragileCargo : public Cargo{
private:
    std::string packagingType, handlingInstructions;
public:
    FragileCargo(int id = 0, double w = 0, double v = 0);
    void pack();
    bool checkPackaging() const;
    void handleWithCare();
};

class GPSPosition{
private:
    double latitude, longitude;
    std::time_t timestamp;
public:
    GPSPosition(double lat = 0, double lon = 0);
    double distanceTo(const GPSPosition& other) const;
    void updatePosition(double lat, double lon);
    bool isMoving(const GPSPosition& other) const;
    };
    
class HRManager : private Employee {
private:
    Employee recruits;
public:
    HRManager(int id = 0, std::string n = "");
    void hire(Employee emp);
    void fire(Employee emp);
    bool conductInterview(Employee emp);
};

class Insurance {
private:
    std::string policyNumber;
    double coverage, premium;
    std::time_t expiryDate;
public:
    Insurance(std::string pol = "", double cov = 0, double prem = 0);
    void renew(std::time_t newExpiry);
    bool claim(double amount);
    bool isActive() const;
};

class Invoice {
private:
    int id;
    double amount;
    std::time_t dueDate;
    bool paid;
public:
    Invoice(int id = 0, double amt = 0);
    void generate(Order order);
    void markPaid();
    bool isOverdue() const;
    double calculateLateFee() const;
};

class LogisticsManager : public Employee{
public:
    LogisticsManager(int id = 0, std::string n = "");
    Route planRoute(Order order);
    void optimizeWarehouse(Warehouse w);
    void coordinateDelivery(Order order);
};

class Machine{
private:
    int id;
    std::string type;
    double hoursUsed;
public:
    Machine(int id = 0, std::string t = "");
    void operate(double hours);
    void scheduleMaintenance();
};

class MaintenanceRecord {
private:
    Vehicle v;
    Mechanic m;
    std::time_t date;
    std::string description;
    double cost;
public:
    MaintenanceRecord(Vehicle v, Mechanic m, std::string desc = "", double c = 0);
    void scheduleNext(std::time_t nextDate);
    double calculateCost() const;
    bool isCompleted() const;
};

class Manager : public Employee{
private:
    int teamSize;
    double budget;
public:
    Manager(int id = 0, std::string n = "");
    bool approveExpense(double amount);
    void assignTask(Driver driv, Order ord, Vehicle veh);
    double calculateTeamPerformance() const;
};

class Mechanic : private Employee{
private:
    std::string specialization;
    std::vector<std::string> certifications;
public:
    Mechanic(int id = 0, std::string n = "");
    void repairVehicle(Vehicle v);
    bool inspectVehicle(Vehicle v);
    void addCertification(const std::string& cert);
};

class Metrics {
private:
    std::vector<std::pair<std::string, double>> metric;
public:
    Metrics();
    double calculateAverage() const;
    double findMax() const;
    double findMin() const;
    void addMetric(double value, std::string name);
};

class Order {
private:
    int id;
    std::time_t orderDate;
    std::string status;
    double totalCost;
    Address pickupAddress, deliveryAddress;
    Client client;
    Driver driver;
    Vehicle vehicle;
    std::vector<Cargo> cargo;
public:
    Order(int id = 0);
    double calculateTotal();
    void assignDriver(Driver d);
    void updateStatus(const std::string& newStatus);
    void cancel();
    bool isDelivered() const;
};

class Payment {
private:
    int id;
    double amount;
    std::string method, status;
    std::time_t date;
public:
    Payment(int id = 0, double amt = 0, std::string meth = "");
    bool process();
    bool refund();
    bool validate() const;
    void markAsPaid();
};

class PerishableCargo : public Cargo {
private:
    std::time_t expiryDate;
    double temperatureRequirement;
    bool cooling;
public:
    PerishableCargo(int id = 0, double w = 0, double v = 0, double tempReq = 0);
    bool checkTemperature(double currentTemp) const;
    bool isExpired() const;
    void setCooling(bool state);
};

class Route {
private:
    int id;
    Address startAddress, endAddress;
    double distance, estimatedTime;
    std::vector<Address> waypoints;
    Route(int id = 0);
    double calculateDistance() const;
    void optimize();
    void addWaypoint(Address addr);
    double getEstimatedTime() const;
};

class Rack {
private:
    int id;
    std::vector<int> cargN;
    double maxWeight, currentWeight;
    int levels;
public:
    Rack(int id = 0, double maxW = 0, int l = 0);
    bool placeItem(double weight, std::vector<Cargo> cargs);
    void removeItem();
    bool checkLoad() const;
};

class Salary {
private:
    Employee emp;
    double baseAmount, bonuses, deductions;
public:
    Salary(Employee emp, double base = 0);
    double calculateNet() const;
    void addBonus(double amount);
    void deduct(double amount);
};

class StorageUnit {
private:
    int id;
    std::string type;
    StorageZone zone;
    std::vector<Rack> racks;
public:
    StorageUnit(int id = 0, int rN = 1, std::string t = "");
    bool storeCargo(Cargo cargo);
    bool retrieveCargo();
    bool isFull() const;
};


class TrackingSystem {
private:
    int id;
    std::map<int, GPSPosition> vehiclePositions;
public:
    TrackingSystem(int id = 0);
    void track(Vehicle v);
    void updateLocation(Vehicle v, GPSPosition pos);
    std::vector<GPSPosition> getHistory(Vehicle v) const;
};

class Trailer{
private;
    int id;
    double capacity;
    std::string type;
    Truck truck;
public:
    Trailer(int id = 0, double cap = 0, std::string t = "");
    void connectTo(Truck t);
    void disconnect();
    bool checkCondition() const;
};

class TransportCompany {
public:
    std::string name;
    Manager mng;
    LogisticsManager lmng;
    std::vector<Warehouse> whss;
    std::vector<WarehouseManager> whms;
    std::vector<Employee> employees;
    std::vector<Driver> drs;
    std::vector<Van> van;
    std::vector<Truck> trks;
    std::vector<Trailer> trls;
    std::vector<Client> clients;
    std::vector<Order> orders;
    TransportCompany(const std::string& n = "");
    void hireEmployee(Employee emp);
    void addWarehouse(Warehouse w);
    void addVehicle(Vehicle v);
    void addTruck(Truck t);
    void addTrailer(Trailer t);
    void registerClient(Client c);
    void createOrder(Order o);
    double calculateRevenue() const;
};

class Truck : public Vehicle{
private:
    Trailer trailer;
    double maxLoad;
public:
    Truck(int id = 0, std::string plate = "", double cap = 0, double maxL = 0);
    void attachTrailer(Trailer t);
    void detachTrailer();
    double calculateFuelConsumption(double distance) const;
};

class Van : public Vehicle {
private:
    double cargoVolume;
    bool refrigeration;
public:
    Van(int id = 0, std::string plate = "", double cap = 0, double vol = 0);
    bool loadCargo(Cargo cargo);
    void unloadCargo();
    bool isRefrigerated() const;
};

class Vehicle {
private:
    int id;
    std::string plateNumber, status;
    double capacity, fuelLevel, mileage;
    Driver driver;
public:
    Vehicle(int id = 0, std::string plate = "", double cap = 0);
    void refuel(double amount);
    void startTrip();
    void endTrip(double distance);
    bool isAvailable() const;
    bool needsMaintenance() const;
};

class Warehouse {
private:
    int id;
   Address location;
    double capacity, currentStock;
    std::vector<Cargo> cargos;
public:
    Warehouse(int id = 0, double cap = 0);
    bool addCargo(Cargo cargo);
    bool removeCargo(Cargo cargo);
    bool checkCapacity(double additionalWeight) const;
    void organizeStorage();
};

class WarehouseManager : public Employee{
private:
    Warehouse w;
public:
    WarehouseManager(int id = 0, std::string n = "");
    void manageInventory();
    void scheduleLoading(Order order);
    bool checkStock(Cargo cargo);
};

class ExpenseTracker {
private:
    std::vector<std::pair<std::string, double>> expenses;
public:
    ExpenseTracker();
    void addExpense(double amount, const std::string& category);
    double getTotalExpenses() const;
    std::map<std::string, double> categorizeExpenses() const;
};

class ProfitAnalyzer {
private:
    double revenue, expenses;
public:
    ProfitAnalyzer(double rev = 0, double exp = 0);
    double calculateProfitMargin() const;
    double analyzeTrend(const std::vector<double>& history) const;
    double predictProfit(double growthRate) const;
};

class TaxCalculator {
private:
    double taxRate;
public:
    TaxCalculator(double rate = 0.2);
    double calculateTax(double income) const;
    double applyDeduction(double income, double deduction) const;
    std::string generateTaxReport(double income) const;
};

class PerformanceMetric {
private:
    double value;
    std::time_t timestamp;
public:
    PerformanceMetric(double val = 0);
    bool compare(const PerformanceMetric& other) const;
    bool isImprovement(const PerformanceMetric& previous) const;
    void record();
};

class FuelConsumption {
private:
    double liters, distance;
    Vehicle v;
public:
    FuelConsumption(double l = 0, double d = 0, Vehicle vh);
    double calculateEfficiency() const;
    void update(double newLiters, double newDistance);
    bool isEfficient(double threshold) const;
};

class TrafficInfo {
private:
    Address location;
    int congestionLevel;
public:
    TrafficInfo(Address loc = nullptr, int level = 0);
    void updateCongestion(int level);
    bool isCongested() const;
    Route suggestAlternative(Route current) const;
};

class CustomerFeedback {
private:
    Client cli;
    int rating;
    std::string comment;
public:
    CustomerFeedback(Client client, int r = 0, std::string c = "");
    bool submit();
    bool validateRating() const;
    void respond(const std::string& response);
};

class ServiceQualityMonitor {
private:
    std::vector<CustomerFeedback> feedbacks;
public:
    ServiceQualityMonitor();
    double calculateAverageRating() const;
    std::vector<std::string> identifyIssues() const;
    std::string generateReport() const;
};

class LoyaltyProgram {
private:
    int points;
    std::string tier;
public:
    LoyaltyProgram(int pts = 0, std::string t = "Bronze");
    void addPoints(int amount);
    bool redeem(int amount);
    void upgradeTier();
};

class StorageZone {
private:
    int id;
    bool temperatureControlled;
public:
    StorageZone(int id = 0, bool temp = false);
    void setTemperature(double temp);
    void monitor();
    bool isSafe() const;
};

class DeliverySchedule {
public:
    int id;
    std::time_t date;
    std::vector<Order> orders;
    DeliverySchedule(int id = 0);
    void addOrder(Order order);
    void optimize();
    bool isFeasible() const;
};

