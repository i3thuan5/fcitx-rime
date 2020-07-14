# for im icon
install(FILES ithuan.png RENAME ithuan.png DESTINATION ${FCITX4_PREFIX}/share/fcitx/imicon)

# for skin
install(DIRECTORY default DESTINATION ${FCITX4_PREFIX}/share/fcitx/skin)

# with prefix
foreach(svg ithuan ithuan-deploy ithuan-sync)
install(FILES ${svg}.png RENAME fcitx-${svg}.png DESTINATION share/icons/hicolor/48x48/apps)
install(FILES ${svg}.svg RENAME fcitx-${svg}.svg DESTINATION share/icons/hicolor/scalable/status)
endforeach()

# without prefix
foreach(svg ithuan-im ithuan-latin ithuan-disable)
install(FILES ${svg}.png DESTINATION share/icons/hicolor/48x48/apps)
install(FILES ${svg}.svg DESTINATION share/icons/hicolor/scalable/status)
endforeach()

# install the config tool icon
install(FILES ithuan128.png RENAME fcitx-ithuan.png DESTINATION share/icons/hicolor/128x128/apps)

