
| Класс | Поля | Методы | Ассоциации |
|---|---:|---:|---|
| Accountant | 0 | 5 | Payment, Order |
| Address | 5 | 4 | GPSPosition |
| BankAccount | 3 | 5 | — |
| Cargo | 5 | 4 | — |
| Client | 5 | 5 | Address, Order, Payment |
| CompanyFinance | 2 | 5 | — |
| CustomerService | 2 | 4 | Employee, Client |
| Dispatcher | 2 | 4 | Order, Driver, Vehicle |
| Driver | 5 | 5 | DrivingLicence, Vehicle |
| DrivingLicence | 4 | 4 | — |
| Employee | 6 | 4 | — |
| Exeptions | 0 | 0 | — |
| ExpressDelivery | 2 | 4 | — |
| FragileCargo | 2 | 4 | — |
| GPSPosition | 3 | 4 | — |
| HRManager | 1 | 4 | Employee |
| Insurance | 4 | 4 | — |
| Invoice | 4 | 5 | Order |
| LogisticsManager | 0 | 4 | Order, Route, Warehouse |
| Machine | 3 | 3 | — |
| MaintenanceRecord | 5 | 4 | Vehicle, Mechanic |
| Manager | 2 | 4 | Driver, Order, Vehicle |
| Mechanic | 2 | 4 | Vehicle |
| Metrics | 1 | 5 | — |
| Order | 10 | 6 | Address, Client, Driver, Vehicle, Cargo |
| Payment | 5 | 5 | — |
| PerishableCargo | 3 | 4 | — |
| Route | 6 | 5 | Address |
| Rack | 5 | 4 | Cargo |
| Salary | 4 | 4 | Employee |
| StorageUnit | 4 | 4 | StorageZone, Rack, Cargo |
| TrackingSystem | 2 | 4 | Vehicle, GPSPosition |
| Trailer | 4 | 4 | Truck |
| TransportCompany | 11 | 9 | Manager, LogisticsManager, Warehouse, WarehouseManager, Employee, Vehicle, Truck, Trailer, Client, Order |
| Truck | 2 | 4 | Trailer |
| Van | 2 | 4 | Cargo |
| Vehicle | 7 | 6 | Driver |
| Warehouse | 5 | 5 | Address, Cargo |
| WarehouseManager | 1 | 4 | Warehouse, Order, Cargo |
| ExpenseTracker | 1 | 4 | — |
| ProfitAnalyzer | 2 | 4 | — |
| TaxCalculator | 1 | 4 | — |
| PerformanceMetric | 2 | 4 | — |
| FuelConsumption | 3 | 4 | Vehicle |
| TrafficInfo | 2 | 4 | Address, Route |
| CustomerFeedback | 3 | 4 | Client |
| ServiceQualityMonitor | 1 | 4 | CustomerFeedback |
| LoyaltyProgram | 2 | 4 | — |
| StorageZone | 2 | 4 | — |
| DeliverySchedule | 3 | 4 | Order |

## Исключения (12)

- `TransportException`
- `InsufficientFundsException`
- `InvalidClientDataException`
- `OrderNotFoundException`
- `InvalidOrderDataException`
- `InvalidCargoDataException`
- `CargoOverweightException`
- `VehicleOverloadException`
- `VehicleNotAvailableException`
- `DriverNotAvailableException`
- `InvalidLicenseException`
- `WarehouseCapacityExceededException`

## Итоговая статистика

| Показатель | Значение |
|---|---:|
| Поля | 161 |
| Поведения | 214 |
| Ассоциации | 62 |
| Исключения | 12 |
