# 🐢 Shellixₒₛ - SubOS Shell Experience

**Shellixₒₛ** is a subOS — an operating system-like app inside an existing OS. It runs Shellix inside a secure, GUI-only environment. Built to feel like a full OS but lightweight and browser-accessible.

## 💡 Features
- Launches as a fullscreen environment (SubOS mode)
- Built-in `.jai` support (Java App Installer)
- ADO (Admin Do) command tool for installing and managing apps
- Secure `.sys` apps (cannot be downloaded or spoofed)
- Access from any device via browser

## 🧠 Example ADO Commands
```bash
ado inst "https://example.com/myapp.jai"
ado start appname
ado start settings.sys
```

## 🛠 Setup
- Open this repo in a GitHub Codespace or run locally
- Ensure Java and a browser are available
- Launch `index.html` or serve via ShellixVM to embed it

## 🔒 Notes
- `.sys` apps are protected — cannot be downloaded, renamed to, or installed from outside Shellix.
