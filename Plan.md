- Phase 1: Planning & Setup
  - Define Features

    Create, edit, and delete goals

    Log progress toward a goal

    View goal completion status

    Categorize goals (e.g., fitness, academic)

    Set deadlines and frequency (daily/weekly/monthly)

    Visual progress bar or percentage

    Streak tracker (optional)

    Tech Stack (Starter Suggestion)

    Language: C++ or Python (command-line), or JavaScript (web-based)

    Database: SQLite or PostgreSQL

    Frontend (Optional for later): HTML/CSS/JS or a framework like React

    Version Control: Git + GitHub

- Phase 2: Design the System
  - Data Models (ERD / OOP Classes)

Goal

    ID (int)

    Name (string)

    Category (string)

    Target Value (e.g., "Run 10 miles")

    Current Progress (float/int)

    Deadline (date)

    Frequency (daily/weekly/etc.)

    CreatedAt / UpdatedAt (timestamp)

ProgressLog

    ID (int)

    GoalID (foreign key)

    Date (date)

    ProgressMade (float/int)

    Notes (optional)

User (optional for single-user MVP)
- Phase 3: Build Core Features
1. Goal Management

Add new goal

Edit existing goal

Delete goal

    View all goals (with filter options)

2. Log Progress

Add progress to a goal

View progress history

    Automatically update total progress

3. Progress Tracking

Calculate % complete

Show days left until deadline

    Visual feedback (progress bar, text status)

- Phase 4: Bonus Features (Stretch Goals)
  - Analytics

    Weekly/monthly progress summaries

    Graph of progress over time (with matplotlib, Chart.js, etc.)

    Notifications/Reminders

    Basic system (console or desktop alert)

    Reminder if no progress in X days

    Authentication (for multi-user support)
    GUI or Web Frontend

    React or simple HTML/CSS/JS

    Mobile-first design if desired

- Phase 5: Testing & Deployment
  - Testing

    Test CRUD operations for goals and progress

    Handle edge cases (e.g., progress > target)

    Data validation (no empty goal names, etc.)

- Deployment

    Store database locally or host via SQLite/PostgreSQL

    Optional: deploy frontend via GitHub Pages or Render
