
function launchApp(name) {
  document.getElementById("app-window").classList.remove("hidden");
  document.getElementById("window-title").innerText = name;
  document.getElementById("focused-app-name").innerText = name;

  if (name === "ado") {
    document.querySelector(".window-body").innerHTML = "<p>Use: ado inst \"link.jai\"</p><p>ado start settings.sys</p>";
  } else if (name === "settings.sys") {
    document.querySelector(".window-body").innerHTML = "<p>System Settings: [FULL ACCESS GRANTED]</p>";
  } else {
    document.querySelector(".window-body").innerHTML = "<p>Launching " + name + "...</p>";
  }
}

function closeApp() {
  document.getElementById("app-window").classList.add("hidden");
  document.getElementById("focused-app-name").innerText = "No App Focused";
}
