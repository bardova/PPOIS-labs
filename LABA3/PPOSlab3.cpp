#include <string>
#include <vector>
#include <memory>
#include <stdexcept>

// ==========================================
// 1. ИЕРАРХИЯ СОБСТВЕННЫХ ИСКЛЮЧЕНИЙ (12 классов)
// ==========================================
class LibraryException : public std::runtime_error {
public:
    explicit LibraryException(const std::string& msg);
};

class BookNotFoundException : public LibraryException {
public:
    BookNotFoundException();
};

class BookUnavailableException : public LibraryException {
public:
    BookUnavailableException();
};

class UserNotFoundException : public LibraryException {
public:
    UserNotFoundException();
};

class UserBlockedException : public LibraryException {
public:
    UserBlockedException();
};

class LoanLimitExceededException : public LibraryException {
public:
    LoanLimitExceededException();
};

class OverdueFineException : public LibraryException {
public:
    OverdueFineException();
};

class InvalidIsbnException : public LibraryException {
public:
    InvalidIsbnException();
};

class InventoryMismatchException : public LibraryException {
public:
    InventoryMismatchException();
};

class ReservationExpiredException : public LibraryException {
public:
    ReservationExpiredException();
};

class PaymentFailedException : public LibraryException {
public:
    PaymentFailedException();
};

class AccessDeniedException : public LibraryException {
public:
    AccessDeniedException();
};

// ==========================================
// 2. ВСПОМОГАТЕЛЬНЫЕ СТРУКТУРЫ И ПЕРЕЧИСЛЕНИЯ
// ==========================================
enum class BookGenre { Fiction, Science, Technology, History, Biography, Fantasy, Art, Philosophy, Law, Medicine };
enum class AccountRole { Reader, Librarian, Administrator, Auditor, Guest, Supplier, Archivist, Director, Technician, Support };
enum class TransactionStatus { Pending, Completed, Cancelled, Refunded, Failed, Disputed, Verified, Audited, Processing, Expired };
enum class NotificationChannel { Email, SMS, Push, Postal, Telegram, WhatsApp, InApp, Console, Webhook, RSS };

struct Date {
    int year;
    int month;
    int day;
    bool isValid() const;
    int toDays() const;
};

struct Address {
    std::string country;
    std::string city;
    std::string street;
    std::string building;
    int apartment;
    std::string postalCode;
    bool validatePostal() const;
    std::string getFullAddress() const;
};

struct Dimensions {
    double width;
    double height;
    double thickness;
    double weight;
    double getVolume() const;
};

// ==========================================
// 3. БАЗОВЫЕ И ПЕРВИЧНЫЕ КЛАССЫ СУЩНОСТЕЙ (Классы 1 - 20)
// ==========================================

class Author {
private:
    std::string authorId;
    std::string firstName;
    std::string lastName;
    Date birthDate;
    std::string biography;
public:
    Author(std::string id, std::string f, std::string l);
    bool validateAuthor() const;
    void archiveAuthorData();
};

class Publisher {
private:
    std::string publisherId;
    std::string name;
    Address address;
    std::string contactEmail;
    int foundationYear;
public:
    Publisher(std::string id, std::string n);
    bool isReliablePartner() const;
};

class Category {
private:
    std::string categoryCode;
    std::string title;
    std::string description;
    bool isRestricted;
    int shelfLevel;
public:
    Category(std::string code, std::string t);
    bool checkAccess(bool isAdult) const;
};

class BookItem {
private:
    std::string barcode;
    std::string isbn;
    std::string title;
    BookGenre genre;
    int publicationYear;
public:
    BookItem(std::string bc, std::string i, std::string t, BookGenre g, int py);
    bool isClassic() const;
    std::string exportMetadata() const;
};

class BookCopy {
private:
    std::string copyId;
    std::string isbn;
    bool isReferenceOnly;
    bool isDamaged;
    double replacementCost;
public:
    BookCopy(std::string id, std::string i, double cost);
    bool isAvailableForLoan() const;
    double calculateDepreciation(int years) const;
};

class Rack {
private:
    int rackNumber;
    std::string hallName;
    int capacity;
    int currentLoad;
    bool climateControlled;
public:
    Rack(int num, std::string hall, int cap);
    bool hasSpace() const;
    double getUtilizationRate() const;
};

class Shelf {
private:
    int shelfId;
    int rackNumber;
    int maxBooks;
    std::string sectionCode;
    bool isSpecialCollection;
public:
    Shelf(int id, int rack, int maxB, std::string sec);
    bool fitsCapacity(int count) const;
};

class LibraryBranch {
private:
    std::string branchId;
    std::string branchName;
    Address location;
    int totalHalls;
    bool isOpen247;
public:
    LibraryBranch(std::string id, std::string name, Address loc);
    bool validateBranch() const;
};

class ReadingRoom {
private:
    int roomId;
    std::string roomName;
    int seatCount;
    bool hasComputers;
    int occupiedSeats;
public:
    ReadingRoom(int id, std::string name, int seats, bool comp);
    bool reserveSeat();
    double getOccupancyRate() const;
};

class Equipment {
private:
    std::string equipmentId;
    std::string modelName;
    bool needsMaintenance;
    int usageHours;
    std::string roomAssignment;
public:
    Equipment(std::string id, std::string model, std::string room);
    bool isOperational() const;
};

class RFIDTag {
private:
    std::string rfidCode;
    std::string bookBarcode;
    bool isActive;
    int signalStrength;
    std::string frequency;
public:
    RFIDTag(std::string code, std::string barcode);
    bool checkIntegrity() const;
};

class BarcodeScanner {
private:
    std::string scannerId;
    std::string firmwareVersion;
    bool isLaserActive;
    int scansPerformed;
    std::string stationLocation;
public:
    BarcodeScanner(std::string id, std::string fw, std::string loc);
    std::string scanCode(const std::string& code);
};

class Printer {
private:
    std::string printerId;
    int paperLevel;
    int tonerLevel;
    bool isColor;
    int pagesPrintedTotal;
public:
    Printer(std::string id, bool color);
    bool printJob(int pages);
    void performCleaningCycle();
};

class Terminal {
private:
    std::string terminalId;
    bool isOnline;
    double cashBoxBalance;
    std::string ipAddress;
    int transactionCount;
public:
    Terminal(std::string id, std::string ip);
    bool dispenseCash(double amount);
};

class Kiosk {
private:
    std::string kioskId;
    std::string locationName;
    bool touchScreenWorking;
    bool cardReaderWorking;
    int dailySessions;
public:
    Kiosk(std::string id, std::string loc);
    bool isFullyOperational() const;
};

class Gate {
private:
    std::string gateId;
    bool isLocked;
    int passageCount;
    bool alarmTriggered;
    std::string directionMode;
public:
    Gate(std::string id);
    void triggerAlarm();
    void resetAlarm();
};

class Camera {
private:
    std::string cameraId;
    std::string resolution;
    bool isRecording;
    int storageUsagePercent;
    std::string zoneName;
public:
    Camera(std::string id, std::string res, std::string zone);
    bool checkHealth() const;
};

class ServerNode {
private:
    std::string nodeId;
    double cpuLoadPercent;
    double ramUsageGb;
    bool isPrimaryCluster;
    int uptimeHours;
public:
    ServerNode(std::string id, bool primary);
    bool isHealthy() const;
};

class BackupSystem {
private:
    std::string backupId;
    Date lastBackupDate;
    bool autoBackupEnabled;
    int archiveRetentionDays;
    double backupSizeMb;
public:
    BackupSystem(std::string id, int retention);
    bool verifyBackupFreshness() const;
};

class Firewall {
private:
    std::string firewallId;
    int blockedIpCount;
    bool ddosProtectionActive;
    int rulesCount;
    std::string securityLevel;
public:
    Firewall(std::string id);
    bool inspectPacket(const std::string& packet) const;
};

// ==========================================
// 4. КЛАССЫ ПОЛЬЗОВАТЕЛЕЙ И АККАУНТОВ (Классы 21 - 32)
// ==========================================

class UserAccount {
protected:
    std::string accountId;
    std::string username;
    std::string passwordHash;
    AccountRole role;
    bool isBlocked;
public:
    UserAccount(std::string id, std::string uname, AccountRole r);
    virtual ~UserAccount() = default;
    bool authenticate(const std::string& pass) const;
};

class Reader : public UserAccount {
private:
    std::string readerTicketNumber;
    int activeLoansCount;
    double accumulatedFines;
    bool isStudent;
public:
    Reader(std::string id, std::string uname, std::string ticket, bool student);
    bool canBorrowMore() const;
};

class Librarian : public UserAccount {
private:
    std::string employeeId;
    std::string workShift;
    int booksProcessedToday;
    double hourlyRate;
public:
    Librarian(std::string id, std::string uname, std::string empId, std::string shift);
};

class Administrator : public UserAccount {
private:
    std::string adminLevel;
    bool hasRootAccess;
    std::string department;
    int securityClearance;
public:
    Administrator(std::string id, std::string uname, std::string level);
    bool verifySecurity(int clearance) const;
};

class Auditor : public UserAccount {
private:
    std::string auditAgency;
    Date licenseExpiry;
    int inspectionsPerformed;
    bool activeInspectionMode;
public:
    Auditor(std::string id, std::string uname, std::string agency);
    bool isLicenseValid() const;
};

class Supplier : public UserAccount {
private:
    std::string companyName;
    std::string contractNumber;
    double totalSuppliedValue;
    int activeOrdersCount;
public:
    Supplier(std::string id, std::string uname, std::string company, std::string contract);
};

class Archivist : public UserAccount {
private:
    std::string archiveSection;
    int rareBooksManaged;
    bool handlesManuscripts;
    int restorationCount;
public:
    Archivist(std::string id, std::string uname, std::string section);
    bool canHandleManuscripts() const;
};

class Director : public UserAccount {
private:
    std::string officeNumber;
    double annualBudget;
    int staffSupervised;
    bool executiveApprovalAuthority;
public:
    Director(std::string id, std::string uname, std::string office, double budget);
};

class Technician : public UserAccount {
private:
    std::string specialization;
    int repairsCompleted;
    bool isEmergencyCalloutReady;
    std::string toolKitId;
public:
    Technician(std::string id, std::string uname, std::string spec, std::string toolkit);
    bool isReady() const;
};

class SupportAgent : public UserAccount {
private:
    std::string supportLanguage;
    int ticketsResolved;
    double satisfactionRating;
    bool isChatActive;
public:
    SupportAgent(std::string id, std::string uname, std::string lang);
};

class GuestSession {
private:
    std::string sessionId;
    std::string ipAddress;
    int pageViews;
    bool sessionExpired;
public:
    GuestSession(std::string id, std::string ip);
    bool isActive() const;
};

class UserProfile {
private:
    std::string profileId;
    std::string fullName;
    std::string phoneNumber;
    Address homeAddress;
    bool newsletterSubscribed;
public:
    UserProfile(std::string id, std::string name, std::string phone, Address addr);
    bool isSubscribed() const;
};

// ==========================================
// 5. КЛАССЫ ПРОЦЕССОВ И ТРАНЗАКЦИЙ (Классы 33 - 42)
// ==========================================

class LoanTransaction {
private:
    std::string transactionId;
    std::string readerId;
    std::string bookCopyId;
    Date issueDate;
    Date dueDate;
    TransactionStatus status;
public:
    LoanTransaction(std::string id, std::string rId, std::string cId, Date issue, Date due);
    bool isOverdue(Date currentDate) const;
};

class ReturnProcess {
private:
    std::string returnId;
    std::string transactionId;
    Date returnDate;
    bool damageDetected;
    double fineApplied;
public:
    ReturnProcess(std::string id, std::string tId, Date retDate);
    bool hasDamage() const;
};

class Reservation {
private:
    std::string reservationId;
    std::string readerId;
    std::string isbn;
    Date expiryDate;
    bool isFulfilled;
public:
    Reservation(std::string id, std::string rId, std::string bookIsbn, Date expiry);
    bool isExpired(Date current) const;
};

class FinePayment {
private:
    std::string paymentId;
    std::string readerId;
    double amountPaid;
    Date paymentDate;
    bool isSuccessful;
public:
    FinePayment(std::string id, std::string rId, double amount, Date date);
    bool verifyPayment() const;
};

class CatalogSearch {
private:
    std::string searchId;
    std::string queryKeyword;
    int resultsFound;
    bool advancedMode;
    std::string filterGenre;
public:
    CatalogSearch(std::string id, std::string query);
    bool hasResults() const;
};

class BookAcquisition {
private:
    std::string acquisitionId;
    std::string supplierId;
    int copiesOrdered;
    double totalCost;
    bool isDelivered;
public:
    BookAcquisition(std::string id, std::string sId, int count, double cost);
    bool checkDeliveryStatus() const;
};

class InventoryAudit {
private:
    std::string auditId;
    std::string librarianId;
    int itemsChecked;
    int discrepanciesFound;
    bool auditCompleted;
public:
    InventoryAudit(std::string id, std::string lId);
    bool hasDiscrepancies() const;
};

class NotificationDispatcher {
private:
    std::string dispatcherId;
    NotificationChannel defaultChannel;
    int queueSize;
    bool serviceActive;
    int sentToday;
public:
    NotificationDispatcher(std::string id, NotificationChannel channel);
};

class ReportGenerator {
private:
    std::string reportId;
    std::string reportType;
    bool includeFinancials;
    int totalPagesGenerated;
    std::string format;
public:
    ReportGenerator(std::string id, std::string type, std::string fmt);
};

class MembershipCard {
private:
    std::string cardNumber;
    std::string readerId;
    Date issueDate;
    bool isActive;
    int loyaltyPoints;
public:
    MembershipCard(std::string num, std::string rId, Date issue);
};

// ==========================================
// 6. КЛАССЫ СТАТИСТИКИ, ИСТОРИИ И ДОПОЛНЕНИЯ (Классы 43 - 50)
// ==========================================

class ReadingStatistics {
private:
    std::string statsId;
    std::string readerId;
    int booksReadTotal;
    int pagesReadTotal;
    double averageRatingGiven;
public:
    ReadingStatistics(std::string id, std::string rId);
};

class BookReview {
private:
    std::string reviewId;
    std::string isbn;
    std::string readerId;
    int rating;
    std::string comment;
public:
    BookReview(std::string id, std::string bookIsbn, std::string rId, int rate, std::string comm);
    bool isPositive() const;
};

class WishList {
private:
    std::string wishListId;
    std::string readerId;
    std::vector<std::string> isbns;
    bool isPublic;
public:
    WishList(std::string id, std::string rId);
    bool containsBook(const std::string& isbn) const;
};

class EventCalendar {
private:
    std::string eventId;
    std::string eventTitle;
    Date eventDate;
    int maxAttendees;
    int registeredAttendees;
public:
    EventCalendar(std::string id, std::string title, Date date, int maxA);
    bool isFull() const;
};

class DigitalArchive {
private:
    std::string archiveId;
    std::string documentTitle;
    double fileSizeMb;
    int downloadsCount;
    bool isRestrictedAccess;
public:
    DigitalArchive(std::string id, std::string title, double size);
    bool checkAccess(bool authorized) const;
};

class LibraryConfiguration {
private:
    std::string configKey;
    std::string configValue;
    bool requiresRestart;
    std::string category;
public:
    LibraryConfiguration(std::string key, std::string val, std::string cat);
    bool isRestartNeeded() const;
};

class SystemLog {
private:
    std::string logId;
    std::string severityLevel;
    std::string message;
    int errorCode;
    bool isArchived;
public:
    SystemLog(std::string id, std::string level, std::string msg, int code);
    bool isCritical() const;
};

class LibraryManager {
private:
    std::string libraryName;
    std::string mainBranchCode;
    int totalBooksManaged;
    double treasuryBalance;
    bool systemMaintenanceMode;
public:
    LibraryManager(std::string name, std::string branch);
};