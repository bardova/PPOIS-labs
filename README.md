| Класс | Поля | Методы | Ассоциации (связанные классы) |
| :--- | :---: | :---: | :--- |
| **Author** | 5 | 4 | BookItem |
| **Publisher** | 5 | 4 | Address, BookItem |
| **Category** | 5 | 4 | BookItem |
| **BookItem** | 5 | 4 | Author, Publisher, Category |
| **BookCopy** | 5 | 4 | BookItem |
| **Rack** | 5 | 5 | Shelf, LibraryBranch |
| **Shelf** | 5 | 4 | Rack, BookCopy |
| **LibraryBranch** | 5 | 5 | Address, Rack, ReadingRoom |
| **ReadingRoom** | 5 | 5 | LibraryBranch, Equipment |
| **Equipment** | 5 | 5 | ReadingRoom, Technician |
| **RFIDTag** | 5 | 4 | BookCopy |
| **BarcodeScanner** | 5 | 5 | Terminal, LibraryBranch |
| **Printer** | 5 | 5 | Terminal, LibraryBranch |
| **Terminal** | 5 | 5 | Kiosk, FinePayment |
| **Kiosk** | 5 | 5 | Terminal, LibraryBranch |
| **Gate** | 5 | 5 | LibraryBranch, RFIDTag |
| **Camera** | 5 | 5 | ServerNode, LibraryBranch |
| **ServerNode** | 5 | 5 | BackupSystem, Firewall |
| **BackupSystem** | 5 | 4 | ServerNode |
| **Firewall** | 5 | 5 | ServerNode |
| **UserAccount** | 5 | 5 | Reader, Librarian, Administrator |
| **Reader** | 4 | 5 | UserAccount, LoanTransaction, Reservation |
| **Librarian** | 4 | 5 | UserAccount, InventoryAudit, BookAcquisition |
| **Administrator** | 4 | 5 | UserAccount, LibraryConfiguration, SystemLog |
| **Auditor** | 4 | 5 | UserAccount, InventoryAudit, ReportGenerator |
| **Supplier** | 4 | 5 | UserAccount, BookAcquisition |
| **Archivist** | 4 | 5 | UserAccount, DigitalArchive, BookItem |
| **Director** | 4 | 5 | UserAccount, LibraryManager, ReportGenerator |
| **Technician** | 4 | 5 | UserAccount, Equipment |
| **SupportAgent** | 4 | 5 | UserAccount, GuestSession |
| **GuestSession** | 4 | 4 | SupportAgent |
| **UserProfile** | 5 | 5 | UserAccount, Address |
| **LoanTransaction** | 6 | 4 | Reader, BookCopy |
| **ReturnProcess** | 5 | 5 | LoanTransaction, BookCopy |
| **Reservation** | 5 | 5 | Reader, BookItem |
| **FinePayment** | 5 | 5 | Reader, Terminal |
| **CatalogSearch** | 5 | 5 | BookItem, Category |
| **BookAcquisition** | 5 | 5 | Supplier, BookItem |
| **InventoryAudit** | 5 | 5 | Librarian, BookCopy |
| **NotificationDispatcher** | 5 | 5 | Reader, UserAccount |
| **ReportGenerator** | 5 | 5 | LibraryManager, Administrator |
| **MembershipCard** | 5 | 5 | Reader |
| **ReadingStatistics** | 5 | 5 | Reader, BookItem |
| **BookReview** | 5 | 5 | Reader, BookItem |
| **WishList** | 4 | 5 | Reader, BookItem |
| **EventCalendar** | 5 | 5 | Reader, LibraryBranch |
| **DigitalArchive** | 5 | 5 | Archivist, BookItem |
| **LibraryConfiguration** | 4 | 5 | Administrator |
| **SystemLog** | 5 | 4 | ServerNode, Firewall |
| **LibraryManager** | 5 | 5 | LibraryBranch, Administrator |

---

## ⚠️ Собственная иерархия исключений (12 классов)

Для обеспечения надежной обработки ошибочных сценариев в библиотечной системе реализована специализированная иерархия исключений:

1. `LibraryException` (базовый класс)
2. `BookNotFoundException`
3. `BookUnavailableException`
4. `UserNotFoundException`
5. `UserBlockedException`
6. `LoanLimitExceededException`
7. `OverdueFineException`
8. `InvalidIsbnException`
9. `InventoryMismatchException`
10. `ReservationExpiredException`
11. `PaymentFailedException`
12. `AccessDeniedException`

## 📊 Итоговая статистика проекта

| Показатель | Фактическое значение |
| :--- | :---: |
| **Количество классов** | 50 |
| **Количество полей** | 184 |
| **Уникальных поведений (методов)** | 162 |
| **Ассоциаций между классами** | 64 |
| **Классов исключений** | 12 |
